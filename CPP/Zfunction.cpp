// Q98 https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string a, string b) {
        //a=haystack AND b=needle
        int i=0,j=0;
        while(i<a.size()){
            if(a[i]==b[j]) i++,j++;
            else{
                i=i-j+1;
                j=0;
            }
            if(j==b.size()) return (i-j);
        }
        return -1;
        
    }
};



//KMP O(n)
class Solution {
    
private : 
    //funtion to find longest prefix sum;
    vector<int> kmpProcess(string needle) {
        int n = needle.size();
        vector<int> lps(n,0);
        int len;
        for(int i=1 , len=0 ;i<n;)
        {
            if(needle[i]==needle[len]) lps[i++] = ++len;
            else if(len) len = lps[len-1];
            else lps[i++] =0;
        }
        return lps;
    }
public:
		int strStr(string haystack, string needle) {
        int m = haystack.size() , n = needle.size();
        vector<int> lps = kmpProcess(needle);
        if(!n) return 0;
        for(int i=0,j=0 ;i < m;){
            if(haystack[i] == needle[j]) i++,j++;
            if(j==n) return (i-j);
            if(i < m && haystack[i] != needle[j]) j ? j = lps[j-1] : i++;
        }
        return -1;
    }
    
    
};
