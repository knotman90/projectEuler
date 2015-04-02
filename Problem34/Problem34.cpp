#include <iostream>


using namespace std;

unsigned int factorial(unsigned int n){
	unsigned int f=1;
	for(unsigned int i=2;i<=n;i++){
		f*=i;
	}
	return f;
}

unsigned int solve(){
	unsigned int result = 0;
	unsigned int i=10;
	while(i<2540161){
		unsigned int sumOfFacts = 0;
		unsigned int number = i;
		while (number > 0) {
		   unsigned int d = number % 10;
		    number /= 10;
		    sumOfFacts += factorial(d);
		}
		
		if (sumOfFacts == i)
		    result += i;
		
		i++;
	}
	return result;
}

	int main(){
		unsigned int result = solve();
		cout<<"Solution is: "<<result<<endl;
	}
