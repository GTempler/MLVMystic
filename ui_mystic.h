/********************************************************************************
** Form generated from reading UI file 'mystic.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSTIC_H
#define UI_MYSTIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mystic
{
public:
    QAction *actionImport;
    QAction *actionAbout;
    QWidget *centralWidget;
    QPushButton *convertButton;
    QListWidget *listWidget;
    QPushButton *removeButton;
    QPushButton *pushButton;
    QProgressBar *progressBar;
    QGroupBox *groupBox;
    QRadioButton *RAWradioButton;
    QRadioButton *MLVradioButton;
    QRadioButton *dualIsoradioButton;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QCheckBox *indexBox;
    QCheckBox *DNGBox;
    QCheckBox *RAWBox;
    QCheckBox *stripeBox;
    QCheckBox *metaBox;
    QComboBox *NConventcomboBox;
    QGroupBox *groupBox_2;
    QCheckBox *MLV_DualISOcheckBox;
    QCheckBox *ChromacheckBox;
    QCheckBox *checkBox_2;
    QComboBox *ChromacomboBox;
    QCheckBox *FolderscheckBox;
    QWidget *page_2;
    QCheckBox *stripeBox_2;
    QWidget *page_3;
    QPushButton *pushButton_2;
    QPushButton *destinationButton;
    QLineEdit *destDirectory;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Mystic)
    {
        if (Mystic->objectName().isEmpty())
            Mystic->setObjectName(QStringLiteral("Mystic"));
        Mystic->setEnabled(true);
        Mystic->resize(615, 682);
        Mystic->setAcceptDrops(true);
        actionImport = new QAction(Mystic);
        actionImport->setObjectName(QStringLiteral("actionImport"));
        actionAbout = new QAction(Mystic);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(Mystic);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        convertButton = new QPushButton(centralWidget);
        convertButton->setObjectName(QStringLiteral("convertButton"));
        convertButton->setGeometry(QRect(310, 600, 121, 23));
        convertButton->setStyleSheet(QStringLiteral(""));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(50, 60, 381, 531));
        listWidget->setAcceptDrops(true);
        listWidget->setDragEnabled(true);
        listWidget->setDragDropOverwriteMode(true);
        listWidget->setDragDropMode(QAbstractItemView::DragDrop);
        listWidget->setDefaultDropAction(Qt::CopyAction);
        listWidget->setResizeMode(QListView::Fixed);
        removeButton = new QPushButton(centralWidget);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setGeometry(QRect(130, 600, 71, 23));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 600, 71, 23));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(50, 40, 381, 16));
        progressBar->setContextMenuPolicy(Qt::DefaultContextMenu);
        progressBar->setMaximum(100);
        progressBar->setValue(0);
        progressBar->setTextVisible(false);
        progressBar->setInvertedAppearance(false);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 0, 371, 31));
        groupBox->setCheckable(false);
        RAWradioButton = new QRadioButton(groupBox);
        RAWradioButton->setObjectName(QStringLiteral("RAWradioButton"));
        RAWradioButton->setGeometry(QRect(130, 10, 91, 17));
        MLVradioButton = new QRadioButton(groupBox);
        MLVradioButton->setObjectName(QStringLiteral("MLVradioButton"));
        MLVradioButton->setGeometry(QRect(30, 10, 82, 17));
        MLVradioButton->setChecked(true);
        dualIsoradioButton = new QRadioButton(groupBox);
        dualIsoradioButton->setObjectName(QStringLiteral("dualIsoradioButton"));
        dualIsoradioButton->setGeometry(QRect(240, 10, 101, 17));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(440, 80, 161, 361));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        indexBox = new QCheckBox(page);
        indexBox->setObjectName(QStringLiteral("indexBox"));
        indexBox->setGeometry(QRect(0, 268, 161, 44));
        indexBox->setChecked(true);
        DNGBox = new QCheckBox(page);
        DNGBox->setObjectName(QStringLiteral("DNGBox"));
        DNGBox->setGeometry(QRect(0, 18, 70, 17));
        DNGBox->setChecked(true);
        RAWBox = new QCheckBox(page);
        RAWBox->setObjectName(QStringLiteral("RAWBox"));
        RAWBox->setGeometry(QRect(0, 240, 70, 40));
        stripeBox = new QCheckBox(page);
        stripeBox->setObjectName(QStringLiteral("stripeBox"));
        stripeBox->setGeometry(QRect(40, 40, 121, 31));
        stripeBox->setCheckable(true);
        stripeBox->setChecked(false);
        stripeBox->setAutoExclusive(false);
        metaBox = new QCheckBox(page);
        metaBox->setObjectName(QStringLiteral("metaBox"));
        metaBox->setGeometry(QRect(0, 328, 91, 40));
        NConventcomboBox = new QComboBox(page);
        NConventcomboBox->setObjectName(QStringLiteral("NConventcomboBox"));
        NConventcomboBox->setGeometry(QRect(40, 210, 111, 22));
        groupBox_2 = new QGroupBox(page);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(39, 79, 121, 121));
        groupBox_2->setAutoFillBackground(false);
        groupBox_2->setFlat(true);
        groupBox_2->setCheckable(false);
        MLV_DualISOcheckBox = new QCheckBox(groupBox_2);
        MLV_DualISOcheckBox->setObjectName(QStringLiteral("MLV_DualISOcheckBox"));
        MLV_DualISOcheckBox->setGeometry(QRect(2, 10, 111, 17));
        MLV_DualISOcheckBox->setAutoExclusive(true);
        ChromacheckBox = new QCheckBox(groupBox_2);
        ChromacheckBox->setObjectName(QStringLiteral("ChromacheckBox"));
        ChromacheckBox->setGeometry(QRect(2, 38, 101, 17));
        ChromacheckBox->setAutoExclusive(true);
        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(2, 90, 101, 20));
        checkBox_2->setAutoExclusive(true);
        ChromacomboBox = new QComboBox(groupBox_2);
        ChromacomboBox->insertItems(0, QStringList()
         << QStringLiteral("2x2")
         << QStringLiteral("3x3")
         << QStringLiteral("5x5")
        );
        ChromacomboBox->setObjectName(QStringLiteral("ChromacomboBox"));
        ChromacomboBox->setGeometry(QRect(40, 60, 69, 22));
        FolderscheckBox = new QCheckBox(page);
        FolderscheckBox->setObjectName(QStringLiteral("FolderscheckBox"));
        FolderscheckBox->setGeometry(QRect(0, 310, 81, 17));
        FolderscheckBox->setChecked(true);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stripeBox_2 = new QCheckBox(page_2);
        stripeBox_2->setObjectName(QStringLiteral("stripeBox_2"));
        stripeBox_2->setGeometry(QRect(0, 20, 121, 31));
        stripeBox_2->setCheckable(true);
        stripeBox_2->setChecked(false);
        stripeBox_2->setAutoExclusive(false);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        stackedWidget->addWidget(page_3);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 600, 75, 23));
        destinationButton = new QPushButton(centralWidget);
        destinationButton->setObjectName(QStringLiteral("destinationButton"));
        destinationButton->setGeometry(QRect(440, 540, 171, 23));
        destDirectory = new QLineEdit(centralWidget);
        destDirectory->setObjectName(QStringLiteral("destDirectory"));
        destDirectory->setEnabled(false);
        destDirectory->setGeometry(QRect(440, 570, 171, 20));
        Mystic->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Mystic);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 615, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        Mystic->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Mystic);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Mystic->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Mystic);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Mystic->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionImport);
        menuHelp->addAction(actionAbout);

        retranslateUi(Mystic);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Mystic);
    } // setupUi

    void retranslateUi(QMainWindow *Mystic)
    {
        Mystic->setWindowTitle(QApplication::translate("Mystic", "Mystic", 0));
        actionImport->setText(QApplication::translate("Mystic", "Import", 0));
        actionAbout->setText(QApplication::translate("Mystic", "About", 0));
        convertButton->setText(QApplication::translate("Mystic", "Convert", 0));
        removeButton->setText(QApplication::translate("Mystic", "Remove", 0));
        pushButton->setText(QApplication::translate("Mystic", "Add", 0));
        groupBox->setTitle(QApplication::translate("Mystic", "Conversion Mode", 0));
        RAWradioButton->setText(QApplication::translate("Mystic", "RAW Convert", 0));
        MLVradioButton->setText(QApplication::translate("Mystic", "MLV Convert", 0));
        dualIsoradioButton->setText(QApplication::translate("Mystic", "Dual Iso Convert", 0));
        indexBox->setText(QApplication::translate("Mystic", "Index Files (Fixes Crashing)", 0));
        DNGBox->setText(QApplication::translate("Mystic", "To DNG", 0));
        RAWBox->setText(QApplication::translate("Mystic", "To RAW", 0));
        stripeBox->setText(QApplication::translate("Mystic", "Vertical Stripes Fix\n"
"       (5D III)", 0));
        stripeBox->setShortcut(QString());
        metaBox->setText(QApplication::translate("Mystic", "Metadata LOG", 0));
        NConventcomboBox->clear();
        NConventcomboBox->insertItems(0, QStringList()
         << QApplication::translate("Mystic", "NAME . ######", 0)
         << QApplication::translate("Mystic", "NAME _ ######", 0)
        );
        NConventcomboBox->setCurrentText(QApplication::translate("Mystic", "NAME . ######", 0));
        groupBox_2->setTitle(QString());
        MLV_DualISOcheckBox->setText(QApplication::translate("Mystic", "Dual ISO (ALPHA)", 0));
        ChromacheckBox->setText(QApplication::translate("Mystic", "Chroma Smooth", 0));
        checkBox_2->setText(QApplication::translate("Mystic", "No Smooth", 0));
        FolderscheckBox->setText(QApplication::translate("Mystic", "Sub Folders", 0));
        stripeBox_2->setText(QApplication::translate("Mystic", "Vertical Stripes Fix\n"
"       (5D III)", 0));
        stripeBox_2->setShortcut(QString());
        pushButton_2->setText(QApplication::translate("Mystic", "Clear All", 0));
        destinationButton->setText(QApplication::translate("Mystic", "Set Destination", 0));
        menuFile->setTitle(QApplication::translate("Mystic", "File", 0));
        menuHelp->setTitle(QApplication::translate("Mystic", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class Mystic: public Ui_Mystic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSTIC_H
