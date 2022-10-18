// https://leetcode.com/problems/powx-n/

// O(log(n))
class Solution {
public:
    double myPow(double x, int p) {
        double res=1;
        if(p==0)
            return res;
        long long n=abs(p);//Rang of int -2147483648 to 2147483647, 
                        // hence the most -ve in +ve will cause overflow hence long long
        while(n){
            if(n%2==1){
                res=res*x;
                n-=1;
            }
            else{
                x=x*x;
                n=n/2;
            }
        }
        return (p<0)?(1/res):res;
    }
};




// O(n)
class Solution {
public:
    double myPow(double x, int p) {
        double res=1;
        if(p==0)
            return res;
        long long n=abs(p);//Rang of int -2147483648 to 2147483647, 
                        // hence the most -ve in +ve will cause overflow hence long long
        for(int i=n;i>0;i--){
            res=res*x;
        }
        return (p<0)?(1/res):res;
    }
};
