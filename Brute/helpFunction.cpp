//
//  helpFunction.cpp
//  pattern2
//
//  Created by Veda on 16/11/4.
//  Copyright © 2016年 Veda. All rights reserved.
//

#include "helpFunction.h"
#include <iostream>
#include "Point.h"
#include<math.h>

//read points from file
// work for test fast and Brute
Point* read(std::istream& is,int& size){
    int s;
    is>>s;
    if(size){
        size=s;
    }
    Point* temp=new Point[s];
    for(int i=0;i<s;i++){
        int _x,_y;
        is>>_x>>_y;
        temp[i]=Point(_x, _y);
        
    }
    return temp;
}
//read points from file
// works when QT is involved 
Point* read(QTextStream& is,int* size){
    int s;
    is>>s;
    if(size){
        *size=s;
    }
    Point* temp=new Point[s];
    for(int i=0;i<s;i++){
        int _x,_y;
        is>>_x>>_y;
        temp[i]=Point(_x, _y);
        
    }
    return temp;
    
}

ostream& operator<<(ostream& os, vector<Collection> lines){
    int size=(int)lines.size();
    for(int i=0;i<size;i++){
        int isize=lines.at(i).getSize();
	cout<<isize<<": ";
	Collection c =lines.at(i);
	Point::origin=c[0];
	for(int j=0;j<isize;j++){
        if(j!=(isize-1))
            os<<"("<<c[j].getX()<<","<<c[j].getY()<<") "<<"->";
        else
            os<<"("<<c[j].getX()<<","<<c[j].getY()<<") "<<"\n";
	}
    }
    return os;
}

void printLines(ostream& os,vector<Collection>& lines){
   int size=(int)lines.size();
    for(int i=0;i<size;i++){
        int isize=lines.at(i).getSize();
	
	Collection c =lines.at(i);
	cout<<isize<<": ";
	Point::origin=c[0];
	for(int j=0;j<isize;j++){
        if(j!=(isize-1))
            //os<<"("<<c[j].getX()<<","<<c[j].getY()<<") "<<((int)(c[j].angleCalculator()*1000000))<<"->";
	 os<<"("<<c[j].getX()<<","<<c[j].getY()<<") "<<"->";
        else
           // os<<"("<<c[j].getX()<<","<<c[j].getY()<<") "<<((int)(c[j].angleCalculator()*1000000))<<endl;
	 os<<"("<<c[j].getX()<<","<<c[j].getY()<<") "<<endl;
	}
    }
    
}
