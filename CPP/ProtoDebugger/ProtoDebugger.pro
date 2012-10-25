#-------------------------------------------------
#
# Project created by QtCreator 2012-10-24T18:48:00
#
#-------------------------------------------------

QT       += core

QT       += gui

QT       += qt3support

TARGET = ProtoDebugger
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    src/protodebugger/model/descriptors/NumberFieldDescriptorContainer.cpp \
    src/protodebugger/model/descriptors/EnumFieldDescriptorContainer.cpp \
    src/protodebugger/model/descriptors/BooleanFieldDescriptorContainer.cpp

HEADERS += \
    src/protodebugger/model/ProtoMessage.h \
    src/protodebugger/model/descriptors/NumberFieldDescriptorContainer.h \
    src/protodebugger/model/descriptors/FieldDescriptorContainer.h \
    src/protodebugger/model/descriptors/EnumFieldDescriptorContainer.h \
    src/protodebugger/model/descriptors/BooleanFieldDescriptorContainer.h
