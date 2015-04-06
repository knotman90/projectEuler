#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

/*
 * A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

The real upperbound is 20161
The total sum is 4179871

real	0m18.279s
user	0m18.256s
  */


#define LIMIT (28123)

unsigned int * divisors;
vector<unsigned int> abudants;

unsigned int sumDivisors (){
	for(unsigned int i=2;i<LIMIT;i++){
		for (unsigned  int j = i*2; j < LIMIT; j+=i) {
			divisors[j]+=i;
		}
	}

	for(int i=0;i<LIMIT;i++)
		if(divisors[i]>i)
			abudants.push_back(i);
}



bool asSumAbudant(unsigned int n){
	unsigned int size=abudants.size();
	for(int i=0;i<size && abudants[i]<n;i++){
		for(int j=i;j<size&& abudants[j]<n;j++){
			if(abudants[i]+abudants[j] == n)
				return true;
		}
	}
	return false;
}

int main(){
	divisors = (unsigned int*)calloc(LIMIT,sizeof(unsigned int));
	sumDivisors();
	unsigned int sum=0;
	unsigned int last=0;
	for(int i=0;i<LIMIT;i++){
		if(!asSumAbudant(i)){
			sum+=i;
			last=i;
		}
	}
	cout<<"The real upperbound is "<<last<<endl;
	cout<<"The total sum is "<<sum<<endl;
	free(divisors);
	return 0;
}
