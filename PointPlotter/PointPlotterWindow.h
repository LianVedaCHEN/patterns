#ifndef POINTPLOTTERWINDOW_H 
#define POINTPLOTTERWINDOW_H 
#include <QtGui>
#include <QStringList>
#include <QLabel>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QPixmap>
#include <vector>
#include <QMessageBox>
#include "Point.h"
#include "solveAlgorithm.h"
#include "helpFunction.h"
#include <time.h>
class PointPlotter:public QMainWindow
{
  Q_OBJECT
public:
  PointPlotter();
  void loadFile();
private slots:
  void bruteMethod();
  void fastMethod();
  void aboutMe();
protected:
  virtual void paintEvent(QPaintEvent* e);
private:
  QAction *bruteAction;
  QAction *fastAction;
  QAction *aboutAction;
  QAction *exitAction;
  QMenu *fileMenu;
  QMenu *helpMenu;
  vector<Collection> result; // to tore the lines satisfying the requirements
  Point* pArray; //to store the points read from file
  void rangeModify();
  int size;
  int minWidth,minHeight,maxWidth,maxHeight;
  QLabel* label;
  QPixmap drawArea;
};

#endif
