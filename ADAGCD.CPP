#include<iostream>
#include<map>
using namespace std;
int sieve[10000001]={0};
int main(){
	int n;
	cin>>n;
	for(int i=0;i<10000001;i++){
		sieve[i]=i;
	}
	for(long long i=2;i<10000001;i++){
		if(sieve[i]==i){
			for(long long j=i*i;j<10000001;j+=i){
				sieve[j]=i;
			}
		}
	}
	map<int,int> factors;
	int flag=0;
	while(n--){
		int num;
		cin>>num;
		while(num--){
			int d;
			cin>>d;
			while(d>1){
				if(flag){
					for(auto it=factors.begin();it!=factors.end();it++){
						int x=0;
						while(d%(it->first)==0){
							x++;
							d/=it->first;
						}
						it->second=min(x,it->first);
					}
				}
				else{
					factors[sieve[d]]++;
					d/=sieve[d];
				}
			}
			flag=1;
		}
	}
	int gcd=1;
	for(auto it=factors.begin();it!=factors.end();it++){
		if(it->second){
			gcd*=(it->first)*(it->second);
		}
	}
	cout<<gcd<<endl;
	return 0;
}