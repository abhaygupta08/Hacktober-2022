#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;
int main(){
	string s = "adobecodebanc";
	string t = "abc";
		// banc
	int n=t.size();
	int m=s.size();

	unordered_map<char,int>t_mp;
	int count=0;
	for(auto it:t){
		t_mp[it]++;
		if(t_mp[it] == 1){
			count++;
		}
	}
	int i=0, j=0;
	int minlen=INT_MAX;
	int s_idx; // store starting idx of min window
	string ans="";

	while(j < m){
		// expand window
		char ch=s[j];
		if(t_mp.find(ch) != t_mp.end()){ // element in t string
			t_mp[ch]--;
			if(t_mp[ch] == 0){
				// window has sufficient occurence of ch
				count--;
			}
		}
		if(count == 0){ // can be valid 
			 minlen=min(minlen,j-i+1);
            s_idx=i;

			// optimise the window
			while(count == 0){
				char st=s[i];
				if(t_mp.find(st) != t_mp.end()){
					t_mp[st]++;
					if(t_mp[st] == 1){
						// means window has to be expand as it needs st char now
						// therefore no longer valid
						count++;
						i++;
					}else{
						// you have sufficient occurrences of 'out'
						// in the  window  hence it is still valid.
						i++;
						 minlen=min(minlen,j-i+1);
            s_idx=i;
					}

				}else{
					// element not in t -> unNecessary char
					i++;
					 minlen=min(minlen,j-i+1);
            s_idx=i;
				}
			}
		}
		j++;
	}
	ans= s.substr(s_idx,minlen);
	cout<< minlen << " " << ans;
	return 0;
}