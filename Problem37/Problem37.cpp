#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

/*
 * The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

	NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 *
 */

std::vector<unsigned int> primes;

bool isProbablyTruncable(unsigned int p){
	unsigned int last=p%10;
	if(last == 1 || last == 9){
		return false;
	}

	return true;
}

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
	primes.push_back(1);
	primes.push_back(2);
	for(int i=3;i<v.size();i+=2){
		if(v[i]){
			primes.push_back(i);
		}
	}

}

bool isTruncable(unsigned int p){
	unsigned int n=p;
	unsigned int magnitude=1;
	if(p<10)
		return true;

	div_t dr;
	while(n>0){
		dr = div(n,10);

		n=dr.quot;
		magnitude*=10;
	}
	magnitude/=10;

	n=magnitude;
	unsigned int nl=p/10;
	unsigned int nr=p - (p/n)*n;
	//cout<<"p nr "<<p<<" "<<nr<<endl;
	while(nr >0){
		//cout<<"p nl nr"<<p<<" "<<" "<<nl<<" "<<nr<<endl;
		if(binary_search(primes.begin()+1,primes.end(),nl)<=0){
			return false;
		}
		nl/=10;

		if(binary_search(primes.begin()+1,primes.end(),nr)<=0){
			return false;
		}

		n/=10;
		nr=nr - (nr/n)*n;
	}
	return true;
}

unsigned int solve(unsigned int bound){
	unsigned int cont=0;
	unsigned int sum=0;
	for(int i=5;i<primes.size();i++){
		if( isTruncable(primes[i]) ){
			cont++;
			sum+=primes[i];
			cout<<primes[i]<<" Is truncable"<<endl;

		}
	}
	return sum;
}

int main(){
	unsigned int bound=1000000;
	sieve(bound);
	cout<<"The solution is:"<<solve(bound)<<endl;
	return 0;
}

