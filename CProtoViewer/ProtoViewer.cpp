#include "ProtoViewer.h"
#include "ui_ProtoViewer.h"

ProtoViewer::ProtoViewer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProtoViewer)
{
    ui->setupUi(this);
}

ProtoViewer::~ProtoViewer()
{
    delete ui;
}
