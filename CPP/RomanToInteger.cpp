class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        map<char,int>RomanLetters;
        RomanLetters['I']=1;
        RomanLetters['V']=5;
        RomanLetters['X']=10;
        RomanLetters['L']=50;
        RomanLetters['C']=100;
        RomanLetters['D']=500;
        RomanLetters['M']=1000;
        int i;
        for(i=0;i<s.length()-1;i++)
        {
            if(RomanLetters[s[i]]<RomanLetters[s[i+1]])
                ans-=RomanLetters[s[i]];
            else   
                ans+=RomanLetters[s[i]];
        }
        ans+=RomanLetters[s[i]];
        return ans;
    }
};
