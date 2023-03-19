class Solution {
public:
    int reverse(int x) {
        if(x>INT_MAX||x<INT_MIN)
                return 0;
        long long rem,var;
        var=x;
        long long ans=0;
        long int temp=1;
        long int r1=pow(2,31);
        long int r2=pow(-2,31);
        if(x>=r2||x<=(r1-1)){
         while(var!=0)
    {
        var=var/10;
        temp=temp*10;
    }
    temp=temp/10;
    while(x!=0){
         rem=x%10;
         x=x/10;
         ans=ans+rem*temp;
         temp=temp/10;
     }   
        if(ans>INT_MAX||ans<INT_MIN)
            return 0;
        else
        return ans;
        }
        else
        {
            if(ans>INT_MAX||ans<INT_MIN)
                return 0;
            else
            return ans;
        }
    }
}; 
