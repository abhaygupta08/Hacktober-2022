// 3Sum Closest
// Leetcode
// question link : https://leetcode.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0,diff=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int s=i+1,e=n-1;
            while(s<e)
            {
                if(nums[i]+nums[s]+nums[e] == target)
                    return nums[i]+nums[s]+nums[e];
                else if(abs(nums[i]+nums[s]+nums[e] - target)<diff)
                {
                    diff=abs(nums[i]+nums[s]+nums[e] - target);
                    ans=nums[i]+nums[s]+nums[e];
                }
                if(nums[i]+nums[s]+nums[e] < target) s++;
                else e--;
            }
        }
        return ans;
    }
};
