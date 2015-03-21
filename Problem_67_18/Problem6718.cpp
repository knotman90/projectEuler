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
	unsigned long** nC;

	n=allocateMatrix(X,Y);
	initializeMatrix(n,X,Y);
	readPiramydMatrixFromFile(path,n,X,Y);
	//printMatrix_if(n,X,Y,[](unsigned long a)->bool {return a!=0;});
	solveProblem(n,X);
	unsigned long max = arrayMax(n[X-1],X);
	cout<<"The longest path cost is: "<<max<<endl;
	deallocateMatrix(n,X);
}







