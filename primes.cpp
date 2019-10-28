#include <bits/stdc++.h>
using namespace std;

//problem found at https://codeforces.com/gym/102267/problem/B
 
#define FR(i, n) for (int i = 0; i < (n); ++i)
 
int main(){
	int x;cin>>x;
 
	bool p[10000001];//is prime
	fill_n(p,10000000,true);
	p[0]=false;
	p[1]=false;
	for(int i=2;i<3200;i++){// use the Sieve method of finding primes
		if(p[i]==false)
			continue;
		for(int o=2;i*o<=10000000;o++){
			p[i*o]=false;
		}
	}
	for(int i=2;i<x;i++){//find the pair of primes
		if(p[i]==true && p[x-i]==true){
			cout<<i<<' '<<x-i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
}