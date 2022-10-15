class Solution {
public:
    string breakPalindrome(string palindrome) {
        bool ok=0;
        int ind=0;
        for(int i=0; i<palindrome.size()/2; i++){
            if(palindrome[i]!= 'a') {ok=1; ind=i; break;}
        }
        if(ok){
         palindrome[ind]='a';   
        }
        else {
            if(palindrome.size()<=1)
            palindrome="";
            else
            palindrome[palindrome.size()-1]='b'; 
        }
        return palindrome;
    }
};
