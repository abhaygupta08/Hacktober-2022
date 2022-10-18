// Q99 https://leetcode.com/problems/implement-strstr/

// Time: O(n)

//KMP O(n)
class Solution {
private:
    vector<int> kmplps(string b){
        int n=b.size();
        vector<int> lps(n,0);
        int len=0,i=1;
        while(i<n){
            if(b[i]==b[len])lps[i++]=++len;
            else if(len) len=lps[len-1];
            else lps[i++]=0;
        }
        return lps;
    }
public:
    int strStr(string a, string b) {     
        int m=a.size();
        int n=b.size();
        vector<int>lps=kmplps(b);
        int i=0,j=0;
        while(i<m){
            if(a[i]==b[j])i++,j++;
            if(j==n) return (i-j);
            if(a[i]!=b[j]) j? j=lps[j-1]:i++;
        }
        return -1;
    }
};
