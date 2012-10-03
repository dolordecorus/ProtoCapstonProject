#ifndef PROTOVIEWER_H
#define PROTOVIEWER_H

#include <QMainWindow>

namespace Ui {
class ProtoViewer;
}

class ProtoViewer : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ProtoViewer(QWidget *parent = 0);
    ~ProtoViewer();
    
private:
    Ui::ProtoViewer *ui;
};

#endif // PROTOVIEWER_H
