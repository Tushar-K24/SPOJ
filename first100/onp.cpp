#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<algorithm>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		stack <char> s;
		string str;
		cin>>str;
		for(int i=0;i<str.length();i++){
			if(str[i]==')'){
				while(s.top()!='('){
					cout<<s.top();
					s.pop();
				}
				s.pop();
			}
			else if(str[i]=='('||str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='^'){
				s.push(str[i]);
			}
			else{
				cout<<str[i];
			}
		}
		cout<<endl;
	}
	return 0;
}