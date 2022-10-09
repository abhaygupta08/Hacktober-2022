#include<bits/stdc++.h>
using namespace std;
void subsequence(string s, int idx, string str=""){
	if(idx>= s.length()) {
		if(!str.length()) cout<<"{}"<<endl;
		else cout<<str<<endl; 
		return;
	}
	 str+= s[idx];
	 subsequence(s, idx+1, str);
	 str.pop_back();
	 subsequence(s, idx+1, str);
}
int main(){
	int n;
	cin>>n;
	string s, str="";
	cin>>s;
	subsequence(s, 0, str);
	return 0;
}
