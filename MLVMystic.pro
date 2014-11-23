#-------------------------------------------------
#
# Project created by QtCreator 2014-01-17T00:37:32
#
#-------------------------------------------------

QT       += core gui

QMAKE_CC= gcc -std=c99

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MLVMystic
TEMPLATE = app

RC_FILE = mystic.rc

SOURCES += main.cpp\
        mystic.cpp \
    modules/lv_rec/raw2dng.c \
    src/chdk-dng.c \
    modules/mlv_rec/mlv_dump.c \
    modules/dual_iso/chroma_smooth.c \
    modules/dual_iso/cr2hdr.c \
    modules/dual_iso/exiftool-bridge.c \
    modules/dual_iso/adobedng-bridge.c \
    modules/dual_iso/dcraw-bridge.c \
    worker.cpp

HEADERS  += mystic.h \
    modules/lv_rec/lv_rec.h \
    modules/lv_rec/qsort.h \
    src/raw.h \
    modules/lv_rec/raw2dng.h \
    src/chdk-dng.h \
    modules/dual_iso/optmed.h \
    modules/dual_iso/wirth.h \
    src/property.h \
    src/propvalues.h \
    modules/mlv_rec/mlv.h \
    modules/mlv_rec/mlv_dump.h \
    modules/dual_iso/qsort.h \
    modules/dual_iso/adobedng-bridge.h \
    modules/dual_iso/dcraw-bridge.h \
    modules/dual_iso/exiftool-bridge.h \
    src/module.h \
    modules/dual_iso/cr2hdr.h \
    worker.h

FORMS    += mystic.ui

OTHER_FILES += \
    src/Makefile.src.config \
    src/convertrle.rb \
    src/generate_stub.rb \
    src/logo.bmp \
    src/Doxyfile \
    src/flasher.map \
    src/font-large.in \
    src/font-med.in \
    src/font-med2.in \
    src/font-small.in \
    src/font-small2.in \
    src/generate-font \
    src/Makefile.src \
    src/ptpcam.txt \
    src/422-jpg.py \
    src/422-tif.py \
    modules/raw_rec/lzma/7zVersion.rc \
    modules/raw_rec/lzma/files
