#include "PointPlotterWindow.h"
#include <QPainter>
#include <QPixmap>
#include <time.h>
using namespace std;
PointPlotter::PointPlotter():pArray(NULL),minWidth(0),minHeight(0),maxWidth(327680),maxHeight(32768)
{     // constructor
      setMinimumSize(600,600);//set the minimized size of teh window
      // four actions corresponding to actions sstriggered by the four buttons in the UI
      bruteAction = new QAction(tr("load &Brute way"), this);
      fastAction = new QAction(tr("load &Fast way"), this);
      exitAction = new QAction(tr("&Exit"), this);;
      aboutAction= new QAction(tr("&About"), this);
      
      //four slots connect the actions with functions
      connect(bruteAction, SIGNAL(triggered()), this, SLOT(bruteMethod()));
      connect(fastAction, SIGNAL(triggered()), this, SLOT(fastMethod()));
      connect(exitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
      connect(aboutAction, SIGNAL(triggered()), this, SLOT(aboutMe()));
      
      //set the menu bar in UI
      fileMenu = menuBar()->addMenu(tr("File"));
      fileMenu ->addAction(bruteAction);
      fileMenu ->addAction(fastAction);
      fileMenu->addSeparator();
      fileMenu->addAction(exitAction);
      
      helpMenu = menuBar()->addMenu(tr("Help"));
      helpMenu ->addAction(aboutAction);
      label =new QLabel();
    
      setCentralWidget(label);
      
      setWindowTitle(tr("PointPlotter"));
      loadFile();
}

void PointPlotter::loadFile(){
  // to load files 
  QStringList arguments =QCoreApplication::arguments();
  QString filename=arguments.at(1);
  if(!filename.isNull()){
      QFile file(filename);
      if(file.open(QIODevice::ReadOnly)){
	  QTextStream is(&file);
	  if(pArray){
	  
	    delete [] pArray;
	  }
      pArray=read(is,&size);
	rangeModify();
      }
      else cout<<"The file name you input is not correct!!! So this may cause segmentation faault!"<<endl;
  }
  
  repaint();
}

void PointPlotter::bruteMethod(){
     Brute bruteforce(pArray,size);
     double time_start=(double)clock();
     result=bruteforce.solve();
     printLines(cout,result);
     double time_end=(double)clock();
     QMessageBox::information(this," Running time ",QString("%1 ms").arg((time_end-time_start)/CLOCKS_PER_SEC));
     repaint();  
     
}

void PointPlotter::fastMethod(){
     Fast fast(pArray,size);
     double time_start=(double)clock();
     result=fast.solve();
     cout<<result<<endl;
     double time_end=(double)clock();
     QMessageBox::information(this," Running time ",QString("%10000 s").arg((time_end-time_start)/CLOCKS_PER_SEC));
     repaint();
  
}
  
void PointPlotter::aboutMe(){
     // pop up the information of author in other words, me!
     QMessageBox::information(this," About ","programmed by CHEN,Lian\n 20328991");
}

void PointPlotter::paintEvent(QPaintEvent* e){
  //overload paintEvent to deal with the events
    int padding= 20;
    // get the height and width so later the coordiates and positions of points can change according to 
    //the size of the window
    int windowHeight=height(),
    pixHeight=windowHeight-2*padding-menuBar()->height(),
    pixWidth=width()-2*padding;
    //calculate the bounds for main area
    int top= padding, 
    left=padding,
    bottom=top+pixHeight,
    right=left+pixWidth;
    // calculate the unit of x and y so that the graph can change according to the size of window
    double xUnit=pixWidth*1.0/maxWidth,
    yUnit=pixHeight*1.0/maxHeight;
    QPainter painter;
    QPixmap drawArea(width(),height()-menuBar()->height());
    drawArea.fill();
    painter.begin(&drawArea);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 10));
    painter.drawLine(padding, pixHeight+padding,padding + pixWidth, pixHeight+padding);
    painter.drawLine(padding, padding, padding, padding+pixHeight);
    //draw the axis
    for(int i = 0; i <= 10; i++) {
       painter.drawLine(padding + static_cast<int>(1.0 * pixWidth / 10 * i), padding  + pixHeight, padding + static_cast<int>(1.0 * pixWidth / 10 * i),padding  + pixHeight - 6);
       painter.drawLine(padding, padding + menuBar()->height() + pixHeight - static_cast<int>(1.0 * pixHeight / 10 * i),padding + 6, padding + menuBar()->height() + pixHeight - static_cast<int>(1.0 * pixHeight / 10* i));
    }
    // mark the ruler
    for(int i = 0; i <= 10; i++) {
      painter.drawText(static_cast<int>(1.0 * pixWidth / 10 * i),padding+pixHeight,50,30,Qt::AlignCenter,QString("%1").arg(maxWidth/10*i));
      painter.drawText(padding,padding + menuBar()->height() + pixHeight - static_cast<int>(1.0 * pixHeight / 10 * i),50,30,Qt::AlignCenter,QString("%1").arg(maxHeight/10*i));
    }
    //draw the points
    for(int j=0;j<size;j++){
      pArray[j].draw(&painter,xUnit,yUnit,bottom,left);
    }
    //draw the lines made up of collinear points
    for(int j=0;j<result.size();j++){
        Collection temp=result.at(j);
	for(int i=0;i<temp.getSize()-1;i++){
	temp[i].drawTo(temp[i+1],&painter,xUnit,yUnit,bottom,left);
	}
   }
    painter.end();
    label->setPixmap(drawArea);
}

void PointPlotter::rangeModify(){
   // This function is called when the file is loaded so if the points are close to origin, my program no need to draw too much long axises.
   int tempMaxX=400;
   int tempMaxY=400;
   for(int i=0;i<size;i++){
     (pArray[i].getX()>tempMaxX&&pArray[i].getX()<=32768)?(tempMaxX=pArray[i].getX()):(tempMaxX=tempMaxX);
     
     (pArray[i].getY()>tempMaxY&&pArray[i].getY()<=32768)?(tempMaxY=pArray[i].getY()):(tempMaxY=tempMaxY);
  
   }

     maxHeight=tempMaxY;
     maxWidth=tempMaxX;
}

