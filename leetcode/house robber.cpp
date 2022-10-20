class Solution {
public:
    int solve(vector<int> &f)
    {
        int n=f.size();
        int prev2=0;
        int prev1=f[0];
        for(int i=1;i<n;i++)
        {
            int incl=prev2+f[i];
            int excl=prev1+0;
            int ans=max(incl,excl);
            prev2=prev1;
            prev1=ans;
            
        }
        return prev1;
        
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        
        return solve(nums);
    } 
};
