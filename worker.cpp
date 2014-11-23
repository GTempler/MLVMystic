#include "worker.h"
#include "modules/mlv_rec/mlv_dump.h"
#include "modules/lv_rec/raw2dng.h"
#include "modules/dual_iso/cr2hdr.h"
#include <QDir>

Worker::Worker(QObject *parent) :
    QObject(parent)
{
}

void Worker::process() {
    // allocate resources using new here
    qDebug("Hello World!");
    emit finished();
}

void Worker::MLVThread(){
    for(int i=QPath.size();i>0;i--){
        QFileInfo seperator(QPath[i-1]);

        std::string directory = get_directory(seperator);
        std::vector<char*> filePaths = get_paths(seperator, directory);

        //Index Files
        if(idb){
            char*myArray[] = {
                "mlv_dump",
                "-x",
                filePaths[0],
                NULL
            };
            mlv_dump(3, myArray, stripe);

        }
        //Metadata File
        if(mtb){
            char*myArray[] = {
                "mlv_dump",
                "-m",
                filePaths[0],
                NULL
            };
            mlv_dump(3, myArray, stripe);

        }


        //Convert to RAW and DNG
        if(r2d) {
            char* myArray[] = {
                        "mlv_dump",
                        "-o",
                        filePaths[1],
                        "-r",
                        filePaths[0],
                        NULL
                        };

            mlv_dump(5, myArray, stripe);
        }

        if(dng != "-----"){

            char* myArray[] = {
                        "mlv_dump",
                        "-o",
                        filePaths[2],
                        dng,
                        filePaths[0],
                        NULL
            };

            mlv_dump(5, myArray, stripe);
        }
        emit updateBar();
    }
    emit finished();
}

void Worker::RAWThread(){
    for(int i=QPath.size();i>0;i--){
        QFileInfo seperator(QPath[i-1]);

        std::string directory = get_directory(seperator);
        std::vector<char*> filePaths = get_paths(seperator, directory);
        char* rawArray[] = {
                    "raw2dng",
                    filePaths[0],
                    filePaths[2],
                    NULL
        };

        raw2dng(3, rawArray, stripe);
        emit updateBar();
    }
    emit finished();
}
void Worker::CR2Thread(){
    for(int i=QPath.size();i>0;i--){
        QFileInfo seperator(QPath[i-1]);

        std::string directory = get_directory(seperator);
        std::vector<char*> filePaths = get_paths(seperator, directory);
        char* cr2Array[] = {
                     "cr2hdr",
                     filePaths[0],
                     NULL
         };

         cr2hdr(2, cr2Array);
         emit updateBar();
    }

    emit finished();
}


/* CREATE AND SET SUB FOLDER */
std::string Worker::get_directory(QFileInfo seperator){
    QString Qdirectory = seperator.path() + "/";
    if(dest != "")
        Qdirectory = dest+ "/";
    if(subFolder)
        Qdirectory += seperator.baseName() + "/";
    std::string directory = Qdirectory.toStdString();
    QDir QdirectPath(Qdirectory);
    if(!QdirectPath.exists())
      QdirectPath.mkpath(".");
    return directory;
}



/* CREATE CHAR FILE PATHS */
std::vector<char*> Worker::get_paths(QFileInfo seperator, std::string directory){
    //Spacer Between Name and Number
    std::vector<char*> filePaths;

    //Prepare Output Filename
    std::string fullPath = seperator.filePath().toStdString();
    std::string newRAWPath = directory + seperator.fileName().toStdString();
    std::string newDNGPath = directory + seperator.baseName().toStdString()+ spacingChar;
    filePaths.push_back(new char [fullPath.size()+1]);
    strcpy(filePaths[0], fullPath.c_str());
    filePaths.push_back( new char [newRAWPath.size()+1]);
    strcpy(filePaths[1], newRAWPath.c_str());
    strcpy(&filePaths[1][strlen(filePaths[1]) - 3], "RAW");
    filePaths.push_back( new char [newDNGPath.size()+1]);
    strcpy(filePaths[2], newDNGPath.c_str());

    return filePaths;
}
