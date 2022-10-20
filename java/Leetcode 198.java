/*
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
*/
class Solution {
   public int rob(int[] nums) {
        if(nums.length==0) return 0;
        if(nums.length==1) return nums[0];
        if(nums.length>2) {
            nums[2]+=nums[0];
        }
        int s1=0,s2=0;
        for(int i=3;i<nums.length;i++){
            nums[i]+=Math.max(nums[i-2],nums[i-3]);
        }
        return Math.max(nums[nums.length-1],nums[nums.length-2]);
    }
}
