//
//  solveAlgorithm.cpp
//  pattern2
//
//  Created by Veda on 16/11/4.
//  Copyright © 2016年 Veda. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include "solveAlgorithm.h"
Brute::Brute():pArray(NULL),pSize(0){
}

Brute::Brute(Point* a,int size):pArray(a),pSize(size){
}

Brute::~Brute(){
}

//The function will check whether the points stored in Brute object can make up lines
//in a bruteforce way
vector<Collection> Brute::solve(){
   
    
    vector<Collection> collectionVector;
    for(int i=0;i<pSize;i++){
        for(int j=i+1;j<pSize;j++){
            for(int k=j+1;k<pSize;k++){
                for(int l=k+1;l<pSize;l++){
                    if(pArray[i].isCollinear(pArray[j],pArray[l],pArray[k])){
		        Collection temp(4);
                        temp[0]=pArray[i];
                        temp[1]=pArray[j];
                        temp[2]=pArray[k];
                        temp[3]=pArray[l];
                        collectionVector.push_back(temp);
                    }
                }
            }
        }
    }
    
    return collectionVector;
}


Collection::Collection():coLinearPoints(NULL),size(0){}

Collection::Collection(int n):coLinearPoints(new Point[n]),size(n){}

Collection::~Collection(){}

Point& Collection::operator[](int n){
    if(n<0||n>=size){
        std::cout<<"what you want to get is not in the collection!"<<std::endl;
    }
    return coLinearPoints[n];
}

Point& Collection::operator[](int n) const{
    if(n<0||n>=size){
        std::cout<<"what you want to get is not in the collection!"<<std::endl;
    }
    return coLinearPoints[n];
}

int Collection::getSize() const{
    return size;
}

//used when sorting
bool Comparator(const Point& p,const Point& q){
    return (p<q);
    
}

Fast::Fast():pArray(NULL),pSize(0){
}

Fast::Fast(Point* a,int size):pArray(a),pSize(size){
}

Fast::~Fast(){
}

//The function will check whether the points stored in Fast object can make up lines
//in a fast way
vector<Collection> Fast::solve(){

    vector<Collection> collectionVector(0);

    for(int i=0;i<pSize-1;i++){
         int tempSize =pSize-i-1;
	 Point::origin=pArray[i];
         vector<Point> arraySorted(0);
	 for(int j=i+1;j<pSize;j++){
	   arraySorted.push_back(pArray[j]);
	 }

	 sort(arraySorted.begin(),arraySorted.end(),Comparator);

	 int segCounter=0;
	 int beginNode=-1;//mark the start poin we have found
	
	 bool first=true;
	  for(int j=0;j<tempSize;j++){
	    if((j<tempSize-1)&&(arraySorted[j]==arraySorted[j+1])){
		segCounter++;
		if(first){
		    beginNode=j;
		    first=false;
		}
	    }
            else if((segCounter!=0)&&(arraySorted[j]!=arraySorted[j+1])) break;
	  }
	  
	  bool testRepetition=false;
	  if(segCounter!=0){
	 for(int k=0;k<i;k++){

	   Point temp= pArray[k];
   
	   if(temp==arraySorted.at(beginNode)) testRepetition=true;

	 }
	  }
	  //to check whether the line is a segment of the line we have found 
	  if((segCounter>=2)&&(!testRepetition)){
            segCounter++;
	      Collection temp(segCounter+1);
	      temp[0]=pArray[i];
	      for(int j=1;j<(1+segCounter);j++){
		  temp[j]=arraySorted[j-1+beginNode];
		
	      }
	      collectionVector.push_back(temp);

	  }

    }
    return collectionVector;
    
}
