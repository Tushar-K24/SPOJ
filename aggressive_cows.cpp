#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int possible(int dist, int n, int c, int position[]){
	int count=1;
	int prev=0;
	for(int i=1;i<n;i++){
		if(count>=c){
			break;
		}
		if(position[i]-position[prev]>=dist){
			count++;
			prev=i;
		}
	}
	if(count<c){
		return 0;
	}
	return 1;
}

int max_dist(int start, int end, int c, int n, int position[]){
	if(start==end){
		if(possible(start,n,c,position)){
			return start;
		}
		return -1;
	}
	int dist=(start+end)/2;
	if(possible(dist,n,c,position)){
		if(!possible(dist+1,n,c,position)){
			return dist;
		}
		max_dist(dist+1,end,c,n,position);
	}
	else{
		max_dist(start,dist,c,n,position);
	}
	return dist;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,c;
		cin>>n>>c;
		int position[100000]={0};
		for(int i=0;i<n;i++){
			cin>>position[i];
		}
		sort(position,position+n);
		int dist=max_dist(0,position[n-1]-position[0],c,n,position);
		cout<<dist<<endl;
	}
	return 0;
}