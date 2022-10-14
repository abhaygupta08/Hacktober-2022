class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res=0,diff=1e5;
        for(int i=0;i<nums.size();i++)
        {
            int l=i+1,r=nums.size()-1;
            while(r>l)
            {
                int sum=nums[l]+nums[r]+nums[i];
                if(abs(target-sum)<abs(diff))
                {
                    diff=abs(target-sum);
                    res=sum;
                }
                if(sum==target)
                    return target;
                if(sum<target)
                    l++;
                else
                    r--;
            }   
        }
        return res;
    }
};
