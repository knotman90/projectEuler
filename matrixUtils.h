/*
 * matrixUtils.h
 *
 *  Created on: 21 Mar 2015
 *      Author: knotman
 */

#ifndef MATRIXUTILS_H_
#define MATRIXUTILS_H_

#include<iostream>
#include <fstream>
#include <cstring>
#include <functional>
using namespace std;

unsigned long** allocateMatrix(int X, int Y){
	unsigned long** p=nullptr;
	p=new unsigned long*[X];
	for(int i=0;i<X;i++){
		p[i] = new unsigned long[Y];
	}
	return p;
}

void deallocateMatrix(unsigned long**p,int X){
	for(int i=0;i<X;i++){
		delete p[i];
	}
	delete p;
}

void printMatrix_if(unsigned long**p,int X, int Y, std::function<bool(unsigned long)> predicate){
	for(int i=0;i<X;i++){
		for(int j=0;j<Y;j++){
			if(predicate(p[i][j]))
				cout<<p[i][j]<<" ";
		}
		cout<<endl;
	}
}

void printMatrix(unsigned long**p,int X, int Y){
	for(int i=0;i<X;i++){
		for(int j=0;j<Y;j++){
			cout<<p[i][j]<<" ";
		}
		cout<<endl;
	}
}

void initializeMatrix(unsigned long**p, int X, int Y,int val=0){
	for(int i=0;i<X;i++)
		for(int j=0;j<Y;j++){
			p[i][j]=val;
		}
}


bool readMatrixFromFile(string path,unsigned long**n , int X , int Y){
	string line;
	ifstream myfile (path);
	if (myfile.is_open())
	{
		unsigned long a;
		for(int i=0;i<X;i++){
			for(int j=0;j<Y;j++){
				if(myfile >> a)
					n[i][j]=a;
				else
					return false;
			}
		}
		myfile.close();
		return true;
	}

	else{
		cerr << "ERROR Unable to open file\n";
		return false;
	}

}


bool readPiramydMatrixFromFile(string path,unsigned long**n , int X , int Y){
	string line;
	ifstream myfile (path);
	if (myfile.is_open())
	{
		unsigned long a;
		for(int i=0;i<X;i++){
			for(int j=0;j<=i;j++){
				if(myfile >> a)
					n[i][j]=a;
				else
					return false;
			}
		}
		myfile.close();
		return true;
	}

	else{
		cerr << "ERROR Unable to open file\n";
		return false;
	}

}


#endif /* MATRIXUTILS_H_ */
