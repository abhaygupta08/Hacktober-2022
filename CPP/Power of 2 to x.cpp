class Solution {
public:
    double myPow(double x, int n) {
    
//  BRUTE TLE T-N S-N
//         double ans=1;
//         long nn=n;
//         if((n==0)||(x==1)) return 1; 
//         if(n==1) return x; 
//         if(x==0) return 0;         
//         if(nn<0) 
//             nn = -1 * nn;        
//         for(long i=1;i<=nn;i++)
//             ans*=x;      
//         if(n<0)
//             ans = (double)(1)/(double)(ans);       
//         return ans;
        
//  OPTIMAL [T(O(Log n))]
        double ans=1;
        long nn=n; // as for -ve value it exceds integer, so take long
        if(nn<0) 
            nn *= -1; // make it +ve initially
        while(nn>0)
        {
            if(nn % 2==1)
            {
                ans *= x;
                nn=nn-1;
            }
            else
            {
                x *= x;
                nn = nn/ 2;
            }
        }
        if(n<0) ans= 1/ans;
        return ans;
    }
};
