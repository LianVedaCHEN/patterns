//
//  solveAlgorithm.hpp
//  pattern2
//
//  Created by Veda on 16/11/4.
//  Copyright © 2016年 Veda. All rights reserved.
//

#ifndef SOLVEALGORITHM_H
#define SOLVEALGORITHM_H

#include <stdio.h>
#include <iostream>
#include "Point.h"
#include <vector>
using namespace std;
//The class is serve as a date type to store the points which can make up a line satisfying the requirements
class Collection{
public:
    Collection();
    ~Collection();
    Collection(int n);
    Point& operator[](int n); //overload the []so it can use like array 
    Point& operator[](int n) const;
    int getSize() const;
private:
    Point* coLinearPoints;
    int size;
    
};

class Brute{
public:
    Brute();
    ~Brute();
    Brute(Point* a,int size);
    vector<Collection> solve();
private:
    Point* pArray;
    int pSize;
};

class Fast{
public:
    Fast();
    ~Fast();
    Fast(Point* a,int size);
    vector<Collection> solve();
private:
    Point* pArray;
    int pSize;
};





#endif /* solveAlgorithm_hpp */
