#include<iostream>

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

void printMatrix(unsigned long**p,int X, int Y){
  for(int i=0;i<X;i++){
    for(int j=0;j<Y;j++){
      cout<<p[i][j]<<" ";
    }
    cout<<endl;
  }
}

void initializeMatrix(unsigned long**p, int X, int Y){
 for(int i=0;i<X;i++)
   for(int j=0;j<Y;j++){
     if(i==0 || j==0)
       p[i][j]=1;
     else
      p[i][j]=0;
   }
  }

void computeSolution(unsigned long** p, int X, int Y){
  for(int i=1;i<X;i++){
   for(int j=1;j<Y;j++){
     p[i][j]=p[i-1][j]+p[i][j-1];
   }
  }
}
int main(){
  int X=0;
  int Y=0;
  cout<<"Insert the dimension of the matrix (20,20) for Project Euler\n:";
  cin>>X; cin>>Y;
  X++;Y++;
  auto pC = allocateMatrix( X, Y);
  initializeMatrix(pC,X,Y);
  //printMatrix(pC,X,Y);
  computeSolution(pC,X,Y);
  cout<<endl; 
  // printMatrix(pC,X,Y);
 cout<<"the result is: "<<pC[X-1][Y-1];
  deallocateMatrix(pC,X);
  return 0;
}
