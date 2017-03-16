//
//  main.cpp
//  pattern2
//
//  Created by Veda on 16/11/3.
//  Copyright © 2016年 Veda. All rights reserved.
//

#include <iostream>
#include "solveAlgorithm.h"
#include "helpFunction.h"
using namespace std;
int main(int argc, const char * argv[]) {
    int size;
    vector<Collection> lines;
    Point* arrayInBrute;
    arrayInBrute=read(cin,size);
    Brute bruteforce(arrayInBrute,size);
    lines=bruteforce.solve();
    cout<<lines<<endl;
    return 0;
}
