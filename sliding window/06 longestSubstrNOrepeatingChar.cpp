#include<iostream>
#include<unordered_map>

using namespace std;

int main() {
	string s = "abcabcbb";
	int n = s.size();

	int i=0, j=0;
	int count=0; int len=-1;
	unordered_map<char,int>mp;
	while(j<n){
		mp[s[j]]++;
		while(mp[s[j]] > 1){ // repeating char
			mp[s[i]]--;
			i++; // it will come out of loop when char at j freq reduces to 1
		}
		len=max(len,j-i+1);
		j++;
	}
	cout<<len;
}