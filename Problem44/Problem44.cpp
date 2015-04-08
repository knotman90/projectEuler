#include <iostream>
#include <cmath>
using  namespace std;

bool isPentagonal(unsigned int n){
	float f = (1+sqrt(1+24*n))/6;
	return (ceilf(f) == f);
}

unsigned int solve(){
	bool go = true;
		unsigned int n;
	for(int i=1;go;i++){
		n = (3*i*i-i)/2;
		for(int j=i-1;j>0;j--){
			unsigned int m = (3*j*j-j)/2;
			if(isPentagonal(n-m) && isPentagonal(n+m)){
				n=(n-m);
				go=false;
				break;
			}
		}
	}
	return n;

}

int main(){

	unsigned int sol = solve();

//	cout<<"The solution is :"<<sol<<endl;

	return 0;
}
