// Q51 https://leetcode.com/problems/combination-sum/

// Time: 2^t * k
// Space: k * x

// k=avg len of every combination
// t= target
// x= no of combinations 

class Solution {
public:
   
    void recf(int ind, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds,int t){
        if(ind==nums.size()){
            if(t==0)
                ans.push_back(ds);
            return;
        }
        
        if(t>=nums[ind]){
            ds.push_back(nums[ind]);
            recf(ind,nums,ans,ds,t-nums[ind]);
            ds.pop_back();
        }
        recf(ind+1,nums,ans,ds,t);

    }
    
     vector<vector<int>> combinationSum(vector<int>& nums, int t) {
        vector<vector<int>> ans;
        vector <int> ds;
        recf(0, nums, ans, ds,t);
        return ans;
    }
};


