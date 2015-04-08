#include <iostream>
#include <vector>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

/*
 * The prime 41, can be written as the sum of six consecutive primes:
				41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?
 */

std::vector<unsigned int> primes;

std::vector<unsigned long> primeSums;

void computePrimeSums(){
	primeSums.resize(primes.size());
	primeSums[0]=0;
	for(int i=1;i<primes.size();i++){
		primeSums[i]+=primeSums[i-1]+primes[i];
		//cout<<primeSums[i]<<endl;
	}
}


unsigned int solve2(unsigned int bound){


	unsigned int max=1;
	unsigned int res=0;
	int seqlen=0;
	for (int i = 0; i < primeSums.size(); i++) {
	    for (int j = i-seqlen-1; j >= 0; j--) {
	    	unsigned int part =primeSums[i]-primeSums[j];
			if(part>bound) break;//part increase as j increase
			if(binary_search (primes.begin(), primes.end(), part)){
				seqlen=i-j;
				res= part;
			}

		}
	}
	return res;

}


///pure brute force
unsigned int solve(){
	unsigned int max=1;
	unsigned int res=0;
	for(int i=primes.size()-1;i>=0;i--){
		unsigned int n = primes[i];
		for(int s=i-1;s>=0;s--){

			unsigned int sum=0;
			unsigned int cont=1;
			for(int c=s;c>=0 && sum<n ;c--,cont++){
				sum+=primes[c];
				if(sum==n && cont>max){
					max=cont;
					res=n;
				}
			}
		}


	}
	return res;
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
	for(int i=1;i<v.size();i++){
		if(v[i])
			primes.push_back(i);
	}
}


int main(){
	unsigned int bound=1000000;
	sieve(bound);
	computePrimeSums();
	cout<<"The solution is:"<<solve2(bound)<<endl;

	return 0;
}
