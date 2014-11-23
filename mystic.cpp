#include "mystic.h"
#include "ui_mystic.h"
#include "worker.h"
#include "modules/mlv_rec/mlv_dump.h"
#include "modules/lv_rec/raw2dng.h"
#include "modules/dual_iso/cr2hdr.h"
#include <QFileDialog>
#include <QListWidget>
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QFileInfoList>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QEventLoop>
#include <QThread>




Mystic::Mystic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mystic)
{
    ui->setupUi(this);
}

Mystic::~Mystic()
{
    delete ui;
}


/* CONVERT MLV to DNG / RAW */
void Mystic::MLVConvert(QList<QString> QPath){
    //Set / Create Directory


    int idb = ui->indexBox->isChecked();
    int mtb = ui->metaBox->isChecked();
    int r2d = ui->RAWBox->isChecked();
    int stripe = ui->stripeBox->isChecked();
    int subFolder = ui->FolderscheckBox->isChecked();
    QString dest = ui->destDirectory->text();


    std::string spacingChar;
    if(ui->NConventcomboBox->currentIndex() == 0)
        spacingChar = ".";
    else
        spacingChar = "_";

    char* dng = new char[6];
    strcpy(dng, "-----");
    if (ui->MLV_DualISOcheckBox->isChecked())
        strcpy(dng, "--dig");
    else if (ui->ChromacheckBox->isChecked()) {
        char chroma[6];
        strcpy(chroma,"--");
        strcpy(dng, strcat(chroma, ui->ChromacomboBox->currentText().toStdString().c_str()));
    }
    else if(ui->DNGBox->isChecked())
        strcpy(dng, "--dng");


    QThread* thread = new QThread;
    Worker* worker = new Worker();
    worker->moveToThread(thread);
    worker->setMLV(spacingChar,subFolder,dest,dng,idb,r2d,mtb,stripe);
    worker->setQPath(QPath);
    connect(worker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    connect(thread, SIGNAL(started()), worker, SLOT(MLVThread()));
    connect(worker, SIGNAL(updateBar()), this, SLOT(updateProgress()));
    connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();

}



/* CONVERT RAW to DNG */
void Mystic::RAWConvert(QList<QString> QPath){
    int stripe = ui->stripeBox->isChecked();
    int subFolder = ui->FolderscheckBox->isChecked();
    QString dest = ui->destDirectory->text();

    QThread* thread = new QThread;
    Worker* worker = new Worker();
    worker->moveToThread(thread);
    worker->setQPath(QPath);
    worker->setRAW(stripe, subFolder, dest);
    connect(worker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    connect(thread, SIGNAL(started()), worker, SLOT(RAWThread()));
    connect(worker, SIGNAL(updateBar()), this, SLOT(updateProgress()));
    connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}



/* CONVERT DUAL ISO IMAGE */
void Mystic::CR2Convert( QList<QString> QPath){
    int subFolder = ui->FolderscheckBox->isChecked();

    QThread* thread = new QThread;
    Worker* worker = new Worker();
    worker->moveToThread(thread);
    worker->setQPath(QPath);
    connect(worker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    connect(thread, SIGNAL(started()), worker, SLOT(CR2Thread()));
    connect(worker, SIGNAL(updateBar()), this, SLOT(updateProgress()));
    connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}

void Mystic::updateProgress(){
//update progress bar
    currentCount--;
    int progress = ((fileCount-currentCount)* 100 * (1/fileCount));
    ui->progressBar->setValue(progress);

    if (progress == 100){
        QString finTitle("Success!");
        QString finText("Your conversion is now complete.");
        QMessageBox::about(this, finTitle, finText);
        ui->listWidget->clear();
        Mystic::setEnabled(1);
    }

}




/* BEGIN CONVERSION PREPERATION */
void Mystic::on_convertButton_clicked()
{


    int i = ui->listWidget->count();
    fileCount = i;
    currentCount = i;
    QList<QString> QPath;

    while(i > 0){
        //Prepare Filepaths
       QPath.push_back(ui->listWidget->item(i-1)->text());
       i--;
    }
    if(QPath.size())
    {
    Mystic::setEnabled(0);

   //     QFileInfo seperator(QPath);

    //Parse Each File
    if(ui->MLVradioButton->isChecked())
        MLVConvert(QPath);

    if(ui->RAWradioButton->isChecked())
        RAWConvert(QPath);

    if(ui->dualIsoradioButton->isChecked())
        CR2Convert(QPath);


    }
}

void Mystic::on_actionImport_triggered()
{
    if(ui->MLVradioButton->isChecked()){
        QStringList files = QFileDialog::getOpenFileNames(
                    this,
                    tr("Select one or more files to convert"),
                    "/home",tr("Magic Lantern Video (*.mlv)"));
        if (!files.isEmpty()) {
            ui->listWidget->addItems(files);
        }
    }
    else if(ui->RAWradioButton->isChecked()){
        QStringList files = QFileDialog::getOpenFileNames(
                    this,
                    tr("Select one or more files to convert"),
                    "/home",tr("RAW Video (*.raw)"));
        if (!files.isEmpty()) {
            ui->listWidget->addItems(files);
        }
    }
    else if(ui->dualIsoradioButton->isChecked()){
        QStringList files = QFileDialog::getOpenFileNames(
                    this,
                    tr("Select one or more files to convert"),
                    "/home",tr("Dual Iso File (*.cr2 *.dng)"));
        if (!files.isEmpty()) {
            ui->listWidget->addItems(files);
        }
    }
}


void Mystic::on_removeButton_clicked()
{
    ui->listWidget->takeItem(ui->listWidget->currentRow());
}

void Mystic::on_pushButton_clicked()
{
    on_actionImport_triggered();
}

void Mystic::on_actionAbout_triggered()
{
    QString Title("MLV Mystic v0.3(beta)");
    QString About("Special thanks to g3gg0, hudson, and the rest of the magic lantern team for\ntheir work on mlv_dump, raw2dng and of course magic lantern which brings out the best in our cameras.\n\nContact gtempler@secondsparkproductions.com");

    QMessageBox::about(this, Title, About);
}

void Mystic::on_MLVradioButton_clicked()
{
    ui->listWidget->clear();
    ui->stackedWidget->setCurrentIndex(0);
    ui->destinationButton->setEnabled(1);
}

void Mystic::on_RAWradioButton_clicked()
{
    ui->listWidget->clear();
    ui->stackedWidget->setCurrentIndex(1);
    ui->destinationButton->setEnabled(1);
}

void Mystic::on_dualIsoradioButton_clicked()
{
    ui->listWidget->clear();
    ui->stackedWidget->setCurrentIndex(2);
    ui->destinationButton->setEnabled(0);
}


void Mystic::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
}

void Mystic::on_destinationButton_clicked()
{
    ui->destDirectory->clear();
    QString Directory = QFileDialog::getExistingDirectory(this,"select destination folder");
    ui->destDirectory->setText(Directory);
}

void Mystic::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasUrls()) {
        event->acceptProposedAction();
    }
}

void Mystic::dropEvent(QDropEvent *event)
{
    QList<QUrl> droppedUrls = event->mimeData()->urls();
    int droppedUrlCnt = droppedUrls.size();
    QFileInfoList checkList;
    for(int i = 0; i < droppedUrlCnt; i++) {
        QString Path = droppedUrls[i].toLocalFile();
        QFileInfo fileInfo(Path);
        checkList.push_back(fileInfo);
    }
    checkDropped(checkList);
    event->acceptProposedAction();
}

void Mystic::checkDropped(QFileInfoList dFiles){
    for(int i = 0; i < dFiles.size(); i++){
        QFileInfo fileInfo(dFiles[i]);
        if(fileInfo.isFile()) {
    // file
            if(ui->MLVradioButton->isChecked()){
                if(fileInfo.suffix().toLower() == "mlv")
                    ui->listWidget->addItem(fileInfo.absoluteFilePath());
            }
            if(ui->RAWradioButton->isChecked()){
                if(fileInfo.suffix().toLower() == "raw")
                    ui->listWidget->addItem(fileInfo.absoluteFilePath());
            }
            if(ui->dualIsoradioButton->isChecked()){
                if(fileInfo.suffix().toLower() == "dng" || fileInfo.suffix().toLower() == "cr2")
                    ui->listWidget->addItem(fileInfo.absoluteFilePath());
            }

        }
        else if(fileInfo.isDir()) {
    // directory
            QDir dirInfo(fileInfo.absoluteFilePath());
            QFileInfoList dirList(dirInfo.entryInfoList());
            dirList.pop_front();
            dirList.pop_front();
            checkDropped(dirList);
        }
        else {
    // none
            QMessageBox::information(this, tr("Dropped, but unknown"), tr("Unknown: %1").arg(fileInfo.absoluteFilePath()));
        }
    }

}




