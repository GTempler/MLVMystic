#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QFileInfoList>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0);
    void setMLV(std::string setSpacing, int setsub, QString setdest,char* setdng, int setidb, int setr2d, int setmtb, int setstripe){
        spacingChar = setSpacing;
        r2d = setr2d;
        idb = setidb;
        mtb = setmtb;
        stripe = setstripe;
        dng = setdng;
        subFolder = setsub;
        dest = setdest;
    };
    void setQPath(QList<QString> setPath){ QPath = setPath; };
    void setRAW(int setstripe, int setsub, QString setdest){ stripe = setstripe; subFolder=setsub; dest=setdest; };


signals:
    void finished();
    void error(QString err);
    void updateBar();
public slots:
    void process();
    void MLVThread();
    void RAWThread();
    void CR2Thread();

private:
    std::string spacingChar;
    char* dng;
    int idb;
    int r2d;
    int mtb;
    int stripe;
    int subFolder = 0;
    QString dest;
    QList<QString> QPath;

    std::string get_directory(QFileInfo seperator);

    std::vector<char*> get_paths(QFileInfo seperator, std::string directory);
};

#endif // WORKER_H
