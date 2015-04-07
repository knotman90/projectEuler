#include <iostream>
#include<vector>

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
cout<<"The total number is "<<n+8<<endl;
}

const unsigned int TARGET = 200;

//1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
unsigned int coins[] ={1,2,5,10,20,50,100,200};

unsigned int solve(){
	vector<unsigned int> indexs;
	//can write TARGET max with TARGET COIN OF 1p
	for(int i=1;i<=TARGET;i++){
		//initialize index to 0,0,0..(i-times)
		unsigned int psum=0;
		unsigned int pos=0;
		bool go = true;
		do{

			for(int p=1;p<=i;p++){
				//find a suitable index here

			}
			//test sum

			//test go
		}while(go);
	}

}

int main(){

	solve2();
	return 0;
}
