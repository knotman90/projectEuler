#include <iostream>
#include <vector>
#include<cstdlib>
#include<algorithm>
using namespace std;


std::vector<unsigned int> primes;

void sieve(unsigned int bound){
	std::vector<bool> v(bound, true);
	unsigned int n=2;
	while(n<bound){
		for(;n<bound && !v[n];n++){}

		for(int i=n*2;i<bound;i=i+n){
			v[i]=false;
		}
		n++;
	}
	primes.push_back(2);
	for(int i=3;i<v.size();i+=2){
		if(v[i])
			primes.push_back(i);
	}
}

//a Number is circular if does not contain
//any even digits or 5 (it has a rotation
//that is divisible by two or 5)
inline bool isCircular(unsigned int p){
	unsigned int n=p;
	unsigned int magnitude=1;
	if(p<10)
		return true;

	div_t dr;
	while(n>0){
		dr = div(n,10);
		if(dr.rem % 2==0 || dr.rem == 5)
			return false;

		n=dr.quot;
		magnitude*=10;
	}
	magnitude/=10;

	unsigned int nn=p;
	n=1;
	while(n<magnitude){
		dr = div(nn,10);
		nn=dr.quot + dr.rem*magnitude;
		if(binary_search(primes.begin(),primes.end(),nn)<=0){
			return false;
		}
		n*=10;
	}
	return true;

}

unsigned int solve(unsigned int bound){

	unsigned int res=0;
	for(int p=0;p<primes.size();p++){
		if(isCircular(primes[p])){
			res++;
		}
	}
	return res;
}


int main(){
	unsigned int bound=1000000;
	sieve(bound);
	cout<<"The solution is:"<<solve(bound)<<endl;
	return 0;
}
