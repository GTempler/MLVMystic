#ifndef MYSTIC_H
#define MYSTIC_H

#include <QMainWindow>
#include <QFileInfoList>

namespace Ui {
class Mystic;
}

class Mystic : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mystic(QWidget *parent = 0);
    ~Mystic();



private slots:

    void on_convertButton_clicked();

    void on_actionImport_triggered();

    void on_removeButton_clicked();

    void on_pushButton_clicked();

    void on_actionAbout_triggered();

    void on_MLVradioButton_clicked();

    void on_RAWradioButton_clicked();

    void on_pushButton_2_clicked();

    void MLVConvert(QList<QString> QPath);

    void RAWConvert(QList<QString> QPath);

    void CR2Convert(QList<QString> QPath);

    void updateProgress();

    void on_destinationButton_clicked();

    void dragEnterEvent(QDragEnterEvent *event);

    void dropEvent(QDropEvent *event);

    void checkDropped(QFileInfoList dFiles);

    void on_dualIsoradioButton_clicked();

private:
    Ui::Mystic *ui;

    float fileCount;
    float currentCount;
};

#endif // MYSTIC_H
