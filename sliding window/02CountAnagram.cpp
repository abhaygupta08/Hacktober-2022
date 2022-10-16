// count substring in s which is anagram// permutation of t string

#include<iostream>
#include<unordered_map>
using namespace std;
bool compare_mp(int* t, int *s){
	for(int i=0;i<26;i++){ // compare for every char
		if(t[i] != s[i])
			return false;
	}
	return true;
}
int main(){
	string s="cbaebabacb";; int n=s.size();
	string t="abc";
	int t_mp[26]={0};
	for(int i=0;i<t.size();i++){
		t_mp[t[i]-'a']++; // save frequency in map for target string 
	}
	// a->1 b->1 c->1
	int k=t.size();
	int i=0,j=0; // window corners
	int s_mp[26]={0};
	int count=0;
	while(j<k){
		// k size window;
		s_mp[s[j]-'a']++;
		j++;
	}
	if(compare_mp(t_mp,s_mp)){
		count++;
	}
	while(j<n){
		//optimise window
		s_mp[s[i]-'a']--;
		i++;
		s_mp[s[j]-'a']++;
		if(compare_mp(t_mp,s_mp)){
		count++;
	}
		j++;
		
	}
	cout<< count;

	return 0;
}