// Q50 https://leetcode.com/problems/subsets-ii/

// Time: 2^n X n
// Space: 2^n X k (k=avg length of the each subset)

class Solution {
public:
    void recf(int ind, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds){
        ans.push_back(ds);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1])continue;
            ds.push_back(nums[i]);
            recf(i+1,nums,ans,ds);
            ds.pop_back();  
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector <int> ds;
        recf(0, nums, ans, ds);
        return ans;
    }
};
