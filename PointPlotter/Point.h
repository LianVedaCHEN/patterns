//
//  Point.hpp
//  pattern2
//
//  Created by Veda on 16/11/3.
//  Copyright © 2016年 Veda. All rights reserved.
//

#ifndef Point_h
#define Point_h

#include <stdio.h>
#include <QPainter>
#include <iostream>
class Point{
public:
    Point();
    Point(int inX,int inY);
    Point(const Point& p);
    ~Point();
    Point operator+(const Point& p) const;    //overload binary +(add) for Point
    Point operator-(const Point& p) const;    //overload binary -(substract) for Point
    Point operator-() const; //overload unary -(minus) for Point
    int operator*(const Point& p) const;   //overload binary *(dot product) for Point
    int operator^(const Point& p)const;   //overload binary ^(cross product) for Point
    Point& operator=(const Point& p);   //overload binary =(assignment) for Point
    Point operator+=(const Point& p);   //overload  +=(add and assign) for Point
    Point operator-=(const Point& p);   //overload  -=(no less than) for Point

    bool operator==(const Point& p) const;
    bool operator!=(const Point& p) const;
    bool operator>(const Point& p) const;
    bool operator<(const Point& p) const;
    bool operator<=(const Point& p);
    bool operator>=(const Point& p);
    int getX() const;
    int getY() const;
    void setX(int n);
    void setY(int n);
    double angleCalculator() const;
    double angleCalculator();
    double getAngle() const;
    bool isCollinear(const Point& p1,const Point& p2);
    bool isCollinear(const Point& p1,const Point& p2,const Point& p3);
    void draw(QPainter* painter, double xUnit,double yUnit,int bottom,int left);
    void drawTo(const Point& q,QPainter* painter, double xUnit,double yUnit,int bottom,int left);
    static Point origin;
private:
    int x,y;

};



#endif /* Point_hpp */
