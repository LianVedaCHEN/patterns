//
//  Point.cpp
//  pattern2
//
//  Created by Veda on 16/11/3.
//  Copyright © 2016年 Veda. All rights reserved.
//

#include "Point.h"
#include <iostream>
#include "math.h"
#include <QPainter>
Point::Point():x(0),y(0){}

Point::Point(int inX,int inY):x(inX),y(inY){}

Point::Point(const Point& p):x(p.getX()),y(p.getY()){}

Point::~Point(){}

Point Point::origin;

Point Point::operator+(const Point &p) const{
    return Point(p.getX()+this->x,p.getY()+this->y);
}

Point Point::operator-(const Point &p) const{
    return Point(x-p.getX(),y-p.getY());
}

Point Point::operator-() const{
    return Point(-x,-y);
}

int Point::operator*(const Point& p) const{
    return x*p.getX()+y*p.getY();
}

int Point::operator^(const Point& p) const{
    return (x * p.getY()) - (y * p.getX());
}

Point& Point::operator=(const Point& p){
    x= p.getX();
    y=p.getY();
    return (*this);
}

bool Point::operator==(const Point& p) const{
    return ((angleCalculator()-p.angleCalculator()>(-(1e-9)))&&((angleCalculator()-p.angleCalculator()<((1e-9)))));
}
// Since we can not use == into double type, this operator overload return true when the difference between two angles is 
//smaller than 1e-9

bool Point::operator!=(const Point& p) const{
    return !(*this==p);
}

bool Point::operator<(const Point& p) const{
    return (angleCalculator()<p.angleCalculator());
}

bool Point::operator<=(const Point& p){
    return (angleCalculator()<=p.angleCalculator());
}

bool Point::operator>(const Point& p) const{
    return (angleCalculator()>p.angleCalculator());
}

bool Point::operator>=(const Point& p){
    return (angleCalculator()>=p.angleCalculator());
}

int Point::getX() const{
    return x;
}

int Point::getY() const{
    return y;
}

void Point::setX(int n){
    x=n;
}

void Point::setY(int n){
    y=n;
}
// const version for angle calculator
// the function will calcaulate teh angle between currenct point and the origin 
double Point::angleCalculator() const{
  double angle;
    if(x==origin.getX()){
      // case1: the x-coordinate is the same
      angle=-10;
    }
    else if(y==origin.getY()){
      angle =(int)0;
      // case1: the y-coordinate is the same
    }
    else{
      //case3 other situation
      double tempX,tempY,tempOX,tempOY;
      tempX =x;tempY=y;tempOX=origin.getX();tempOY=origin.getY();
      angle=atan((tempY-tempOY)/(tempX-tempOX));
    }
    return angle;
}

// non-const version for angle calculator
// the function will calcaulate teh angle between currenct point and the origin 
double Point::angleCalculator(){
     double angle;
    if(x==origin.getX()){
      // case1: the x-coordinate is the same
        angle=-10;
    }
    else if(y==origin.getY()){
     // case1: the y-coordinate is the same
	angle =(int)0;
      
    }
    else{
          //case3 other situation
      double tempX,tempY,tempOX,tempOY;
      tempX =x;tempY=y;tempOX=origin.getX();tempOY=origin.getY();
      angle=atan((tempY-tempOY)/(tempX-tempOX));

    }
    return angle;
}

Point Point::operator+=(const Point& p){
    x=p.getX()+x;
    y=p.getY()+y;
    return (*this);
}

Point Point::operator-=(const Point& p){
    x=p.getX()-x;
    y=p.getY()-y;
    return (*this);
}
bool Point::isCollinear(const Point& p1,const Point& p2){
    return ((p1-(*this))^(p2-(*this)))==0;
    /*use the cross product to determin whether the three point is on the same line
     principle behind: the cross product of two co-start vectos is the twice of the area of a triangle two vectors form. If the area is zero, three point on the same line.
     */
}

bool Point::isCollinear(const Point& p1,const Point& p2,const Point& p3){
    return (isCollinear(p1, p2)&&isCollinear(p1,p3)&&isCollinear(p1, p2));
}

//this function is to check whether three points are collinear
void Point::draw(QPainter* painter, double xUnit,double yUnit,int bottom,int left){
    painter->setPen(Qt::red);
    painter->drawEllipse( static_cast<int>(x * xUnit + left) - 2, static_cast<int>(bottom - y * yUnit) - 2, 4, 4);
    
}

//this function is to check whether four points are collinear
//it is the overloaded version of the last function
void Point::drawTo(const Point& q,QPainter* painter, double xUnit,double yUnit,int bottom,int left){
    painter->setPen(Qt::blue);
    painter->drawLine(static_cast<int>(x * xUnit + left) , static_cast<int>(bottom - y * yUnit) ,static_cast<int>(q.getX() * xUnit + left) , static_cast<int>(bottom - q.getY() * yUnit) );
}










