#include <iostream>
using namespace std;

void solve2(){
	unsigned int n=0;
	unsigned int sum=0;
		for(int one=0;one<2;one++){
			sum+=one*100;
			for (int fifty = 0; fifty < 4 && sum<=200; fifty++) {
				sum+=fifty*50;
				for (int tewnty = 0; tewnty < 10 && sum<=200; ++tewnty) {
					sum+=tewnty*20;
					for (int ten = 0; ten < 20 && sum<=200; ++ten) {
						sum+=ten*10;
						for (int five = 0; five < 40 && sum<=200; ++five) {
							sum+=five*5;
							for (int twop = 0; twop < 100 && sum<=200; ++twop) {
								sum+=twop*2;
								for (int onep = 0; onep < 200 && sum<=200; ++onep) {
									sum+=onep;
									if(sum==200){
										n++;
									}
									sum-=onep;
								}//onep
								sum-=twop*2;
							}//twop
							sum-=five*5;
						}//five
						sum-=ten*10;
					}//ten
					sum-=tewnty*20;
				}//twenty
				sum-=fifty*50;
			}//fifty
			sum-=one*100;
		}//hundred

//+8 because of the trivial solution given by 1*200,2*100,4*50 etc.
cout<<"The Solution is "<<n+8<<endl;
}

int main(){
	solve2();
	return 0;
}
