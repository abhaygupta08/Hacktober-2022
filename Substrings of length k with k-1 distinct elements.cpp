// Substrings of length k with k-1 distinct elements
// GFG
// question link : https://practice.geeksforgeeks.org/problems/substrings-of-length-k-with-k-1-distinct-elements/1

class Solution {
  public:
    int countOfSubstrings(string S, int k) {
        // code here
        map<char,int> mp;
        int ans=0;
        for(int i=0;i<k;i++)
        {
            mp[S[i]]++;
        }
        if(mp.size()==k-1)
        {
            ans++;
        }
        for(int i=k;i<S.length();i++)
        {
            mp[S[i-k]]--;
            if(mp[S[i-k]]==0)
            {
                mp.erase(S[i-k]);
            }
            mp[S[i]]++;
            if(mp.size()==k-1)
            {
                ans++;
            }
            
        }
        return ans;
    }
};
