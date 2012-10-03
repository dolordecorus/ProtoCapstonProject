#include <QtGui/QApplication>
#include "ProtoViewer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ProtoViewer w;
    w.show();
    
    return a.exec();
}
