class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n=nums.size();
        int i;
        
        if(k>n){
            k=k%n;
        }
        
        vector<int>arr2(n);
        
        for(i=0;i<n;i++){
            arr2[i]=nums[i];
        }
        
        for(i=0;i<n;i++){
        nums[(i+k)%n]=arr2[i];
    }
        
    }
};
