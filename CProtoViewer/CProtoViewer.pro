#-------------------------------------------------
#
# Project created by QtCreator 2012-09-23T23:40:20
#
#-------------------------------------------------
QT       += core gui

TARGET = CProtoViewer
TEMPLATE = app

SOURCES += main.cpp \
        ProtoViewer.cpp \
    model/descriptors/NumberFieldDescriptorContainer.cpp

HEADERS  += ProtoViewer.h \
    model/descriptors/FieldDescriptorContainer.h \
    model/descriptors/ProtoMessage.h \
    model/descriptors/NumberFieldDescriptorContainer.h

FORMS    += ProtoViewer.ui
