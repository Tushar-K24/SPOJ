#include<iostream>
#include<vector>
using namespace std;

bool isPrime(int n){
	if(n==1) return false;
	for(int i=2;i*i<=n;i++)
		if(n%i==0) return false;
	return true;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m; cin>>n>>m;
		for(int i=n;i<=m;i++)
			if(isPrime(i)) cout<<i<<endl;
	}
	return 0;
}
