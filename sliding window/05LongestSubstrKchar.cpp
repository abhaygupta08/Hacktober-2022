#include<iostream>
#include<unordered_map>

using namespace std;

int main() {

	string s = "aabacbebebe";
	int n = s.size();
	int k = 3;
	int i=0, j=0;
	unordered_map<char,int>mp;
	int count=0; // to keep track of no. of unique characters in the window
	int len=-1;
	while(j<n){
		mp[s[j]]++;
		if(mp[s[j]] == 1){
			count++; // a unique char found
		}
		while(count > k){ // optimise the window
			mp[s[i]]--;
			if(mp[s[i]]==0){
				// means succesfully element deleted
				count--;
			}
			i++;
		}

		if(count==k){
			len=max(len,j-i+1);
		}

		j++;
	}
	cout<<len;
}
