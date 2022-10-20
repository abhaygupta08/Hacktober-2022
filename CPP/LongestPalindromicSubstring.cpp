class Solution {
public:
    
// BRUTE [T(O(~N^3))] [S(O(1))]
    // bool isPalindrome(string str)
    // {
    //     string rev=str;
    //     reverse(str.begin(),str.end());
    //     return str==rev;
    // }
    
    
    string longestPalindrome(string s) {
// BRUTE [T(O(~N^3))] [S(O(1))]
        // int len=s.length();
        // int maxPal=1;
        // string ans="";
        // for(int i=0;i<len;i++)
        // {
        //     for(int j=i;j<len;j++)
        //     {
        //         if(s[i]==s[j])
        //         {
        //             int l=j-i+1;
        //             if((maxPal<=l) && isPalindrome(s.substr(i,l)))
        //             {                    
        //                 ans=s.substr(i,l);
        //                 maxPal=l;
        //             }
        //         }
        //     }
        // }
        // return ans;
        if(s.length()<2) return s;
        int maxLen=0;
        int start=0;
        for(int i=0;i<s.length();i++)
        {
            int oddLen=expandFromMid(s,i,i);// for odd palindrome
            int evenLen=expandFromMid(s,i,i+1);// for even palindrome
            if(maxLen<max(oddLen,evenLen))
            {
                maxLen=max(oddLen,evenLen);
                start=i-(maxLen-1)/2;
            }
        }
        return s.substr(start,maxLen);
    }
    
        
    int expandFromMid(string s,int left,int right)
    {
        while(left>=0 && right<s.length() && s[left]==s[right])
        {
            left--;
            right++;
        }
        return right-left-1;
    }
};
