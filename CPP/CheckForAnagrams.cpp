// Q101 https://leetcode.com/problems/valid-anagram/

// Time: O(n)
// Space: O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        int freqs[26]={0};
        int freqt[26]={0};
        for(char ch:s) freqs[ch-'a']++;
        for(char ch:t) freqt[ch-'a']++;
        for(int i=0;i<26;i++){
            if(freqs[i]!=freqt[i]) return false;
        }
        return true;
    }
};

// Time: O(nlogn)
// Space: O(1)
bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s.size()!=t.size()){
            return 0;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){
                return 0;
            }
        }
        return 1;
    }
