/*
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
*/
class Solution {
    public int rob(int[] nums) {
        return Math.max(nums[0],Math.max(solve(nums,0,nums.length-2),solve(nums,1,nums.length-1)));
    }
    int solve(int[] nums,int start,int end){
        int rob1=0,rob2=0,res=0;
        
        for(int i=start;i<=end;i++){
            res=Math.max(rob1+nums[i],rob2);
            rob1=rob2;
            rob2=res;
        }
        return res;
    }
}
