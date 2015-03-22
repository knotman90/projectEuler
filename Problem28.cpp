#include<iostream>
#include <cstring>
#include "matrixUtils.h"

using namespace std;
void initMatrix(unsigned long **m , int X, int Y){
int c=0;
int tr=1;
for(int c=0;c<X/2;c++){
	tr=c*4+1;
cout<<tr<<endl;
}

}

int main(){
int X,Y;
string path="problem29Input.dat";
cout<<"Insert Matrix (sqare) size:"<<endl;
cin>>X; Y=X;

unsigned long** m=0;
m = allocateMatrix(X,Y);



deallocateMatrix(m,X);

 return 0;
}
