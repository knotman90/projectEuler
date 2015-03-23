#include<iostream>



using namespace std;

void solveProblem(int X){
	int c=1;
	int tr=1;
	int br=1;
    int bl=1;
    int tl=1;
	unsigned long sum=1;
	for(int i=0;i<X/2;i++){
		tr+=(c+2)*2+2*c;
        br=tr-(c+2)*2-c+1;
        bl=br+(c+2)-1;
        tl=bl+(c+2)-1;
		sum+=tr+br+bl+tl;
		c+=2;
	}
	
	cout<<"The total sum is "<<sum;

}

int main(){
	int X;
	cout<<"Insert Matrix (sqare) size:"<<endl;
	cin>>X;
	solveProblem(X);


 return 0;
}
