class Solution {
public:
    void nextPermutation(vector<int>& nums) {
// Direct inbuilt function
    // (next_permutation(nums.begin(),nums.end()));
        
//OPTIMAL T(O(N)) S(O(1))
        int r,l,size=nums.size();
        for(l=size-2;l>=0;l--)
        {
            if(nums[l]<nums[l+1])
                break;
        }
        if(l<0)
            reverse(nums.begin(),nums.end());
        else
        {
            for(r=size-1;r>l;r--)
            {
                if(nums[r]>nums[l])
                    break;
            }          
            swap(nums[r],nums[l]);
            reverse(nums.begin()+l+1,nums.end());
        }
    }
};
