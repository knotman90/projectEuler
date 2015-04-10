#include<iostream>


using namespace std;


int main(){
	/*
	 * a^b+b^2=c^2
	 * if a and b even => c even
	 * if just a even => c even
	 * if just b even => c even
	 * 	 */
unsigned long bound=1000;
	unsigned long max=0;
	unsigned long sol=0;
	unsigned long res=0;
	for(long p=2;p<bound;p+=2){
		unsigned long sol=0;
		for(unsigned long a=1;a<(p/3);a++){
			unsigned long  n = p*(p-2*a);
			unsigned long d=2*(p-a);
			if(n%d==0){
				sol++;
			}
		}
		if(sol>max){
			max=sol;
			res=p;
		}
	}
	cout<<"The solution is: "<<res<<" with "<<max<<" solutions"<<endl;
	return 0;
}
