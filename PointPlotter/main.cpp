#include <QApplication>
#include "PointPlotterWindow.h"

int main(int argc, char* argv[]){
    QApplication a(argc,argv);
    QWidget* w =new PointPlotter();
    w->show();
    return a.exec();
  
}