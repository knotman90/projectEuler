#include<iostream>
#include <cstring>
#include "matrixUtils.h"

using namespace std;


int main(){
int X,Y;

cout<<"Insert Matrix (sqare) size:"<<endl;
cin>>X; Y=X;

unsigned long** m=0;
m = allocateMatrix(X,Y);



deallocateMatrix(m,X);

 return 0;
}
