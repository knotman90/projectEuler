#include <iostream>
#include<cmath>
using namespace std;

unsigned long long pow (int b, int e){
	if(e==0)
		return 1;
	unsigned long long r =b;
	for(int i=0;i<e-1;i++){
		r*=b;
	}
	return r;
}

void mult(){
	//try either with p =1010101030 and  p =1010101070
	unsigned long long p=1010101030;//~sqrt(1020304050607080900);
	unsigned long long upperBound = 1389026623;//~sqrt(192939495969798990);
	unsigned long long m=0;

	bool found=false;
	while(p<=upperBound && !buono){
		found=true;
		m=p*p;
		int digit=9;
		for(int i=2;i<=18;i=i+2,digit--){
			if(!( (m/pow(10,i))%10 == digit )  )
				found=false;
		}

		if(found)
			cout<<"Solution is"<<p<<endl;

		p+=100;
	}

}

int main(){
	mult();

	return 0;
}
