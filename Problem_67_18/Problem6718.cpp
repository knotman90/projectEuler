/*
 * Problem18.cpp
 *
 *  Created on: 21 Mar 2015
 *      Author: knotman
 */
#include<iostream>
#include <cstring>
#include <climits>
#include "../matrixUtils.h"

using namespace std;

/**
 * IMPORTANT: options -std=c++11 needed to compile this file!
 * Strategy:
 * Read the matrix from the file
 * Iteratively starting from level zero compute the longest path to each node
 * by checking the alternative route (at most two for each node).
 *
 *INPUT:
 * 	75
	95 64
	17 47 82
	18 35 87 10
	20 4 82 47 65

	OUTPUT (max of the last row):
	75
	170 139
	187 217 221
	205 252 308 231
	225 256 390 355 296

 *
 * */
void solveProblem(unsigned long** n, int X){
	for(int i=1;i<X;i++){
		for(int j=0;j<=i;j++){
			if(j>0 && j<i){
				unsigned long r =n[i][j]+ n[i-1][j];
				unsigned long l =n[i][j]+ n[i-1][j-1];
				n[i][j] = r > l ? r : l;
			}else{
			n[i][j]= j==0 ? (n[i][j]+n[i-1][j]) : ((n[i][j]+n[i-1][j-1]));
			}
		}
	}
}

unsigned long arrayMax(unsigned long* n, int dim){
	unsigned long max=0;
	for(int i=1;i<dim;i++){
		max= n[i] > max ? n[i] : max;
	}
	return max;
}

int main(){
	string path="./numbers.dat";
	int X,Y;
	cout<<"Insert the depth of the piramyd\n:";
	cin>>X;
	Y=X;
	unsigned int level=1000;
	unsigned long** n;


	n=allocateMatrix(X,Y);
	initializeMatrix(n,X,Y);
	readPiramydMatrixFromFile(path,n,X,Y);
	printMatrix_if(n,X,Y,[](unsigned long a)->bool {return a!=0;});
	solveProblem(n,X);
	unsigned long max = arrayMax(n[X-1],X);
	cout<<"The longest path cost is: "<<max<<endl;
	printMatrix_if(n,X,Y,[](unsigned long a)->bool {return a!=0;});
	deallocateMatrix(n,X);
}







