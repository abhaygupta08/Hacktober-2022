class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        int z=0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) if(nums[i]==0) z++;
        for(int i=0; i<nums.size()-2; i++){

            if(nums[i+1]>=0 && nums[i]== nums[i+1]) continue;
            int l=i+1, h=nums.size()-1;
            while(l<h){
                int tar= nums[i]+nums[l]+nums[h];
                if(tar>0) h--;
                else if(tar<0) l++;
                
                else{
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[l]);
                    v.push_back(nums[h]);
                    sort(v.begin(), v.end());
                    s.insert(v); 
                    l++;
                    h--;
                }
            }
        }
        vector<vector<int>> v;
        for(auto it: s) v.push_back(it);
        if(z>=3) v.push_back({0,0,0}); 
        return v;
    }
};
