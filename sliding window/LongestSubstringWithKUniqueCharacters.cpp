#include<iostream>
#include<unordered_map>

using namespace std;

int main() {

	string s = "aabacbebebe";
	int n = s.size();
	int k = 3;
	int i=0; // to store the start of the window
	int j=0; // to store the end of the windw

	unordered_map<int,int>mp;
	int count=0; // to keep track of no. of unique characters in the window 
	int max_length=0;

	while(j<n){
		// expand window
		mp[s[j]]++;
		// if a element found->count+
		if(mp[s[j]]==1) {
			count++;
		}
		// optimizing string
		while(count>k){
			mp[s[i]]--;
			if(mp[s[i]]==0){
				count--;
			}
			i++;
		}
		if(count==k){
			// check for max length for valid strings
			max_length=max(max_length,j-i+1);
		}
		j++;
	}
	cout<< max_length;

}