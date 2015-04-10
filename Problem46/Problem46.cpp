#include <iostream>
#include <vector>
using namespace std;

std::vector<unsigned int> primes;
std::vector<unsigned int> oddComposites;


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
		if(v[i])
			primes.push_back(i);
		else
			oddComposites.push_back(i);
	}
}

unsigned int solve2(unsigned int bound){
	for(int c=0;c<oddComposites.size();c++){
		unsigned int sum=0;
		bool go=true;
		for(int p=0;p<primes.size() && go && primes[p]<oddComposites[c] ;p++){
			for(int s=1;go;s++){
				sum=primes[p]+2*s*s;
				if(sum==oddComposites[c]){
					go=false;
				}else if(sum>oddComposites[c])
					break;
			}
		}
		if(go){
			return oddComposites[c];
		}

	}
}

int main(){
	unsigned int bound=1000000;
	sieve(bound);
	cout<<"The solution is:"<<solve2(bound)<<endl;
	return 0;
}

