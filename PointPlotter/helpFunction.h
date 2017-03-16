//
//  helpFunction.hpp
//  pattern2
//
//  Created by Veda on 16/11/4.
//  Copyright © 2016年 Veda. All rights reserved.
//

#ifndef HELPFUNCTION_H
#define HELPFUNCTION_H

#include <stdio.h>
#include <iostream>
#include <QTextStream>
#include <vector>
#include "Point.h"
#include "solveAlgorithm.h"
Point* read(std::istream& is,int& size);// read points from file when testing fast or brute only
Point* read(QTextStream& is,int* size);// read points from file when QT involved
//below two functions are the same, they are used to print the lines stored in Coolection::lines
ostream& operator<<(ostream& os, vector<Collection> lines);
void printLines(ostream& os,vector<Collection>& lines);

#endif /* helpFunction_hpp */
