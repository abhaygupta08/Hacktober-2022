/*
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/

class Solution {
    public boolean canJump(int[] nums) {
        int n=nums.length,last=n-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]+i>=last)
                last=i;
        }
        
        return last==0;
    }
}
