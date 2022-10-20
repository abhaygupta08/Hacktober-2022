#include<bits/stdc++.h>
using namespace std;
//PROBLEM LINK:https://leetcode.com/problems/integer-to-roman/
/* 
    IN THIS PROBLEM A NUMBER IS GIVEN AND WE HAVE TO CONVERT INTO ROMAN
     */




class Solution {
public:
   
    string intToRoman(int num) {
          string arr[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
      int numb[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string ans = "";
       for(int i=12;i>=0;i--){
           while(num-numb[i]>=0){
               ans+=arr[i];
               num = num-numb[i];
           }
       }
        return ans;
    }
};
int main(){
    return 0;
}