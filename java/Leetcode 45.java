/*
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/
class Solution {
    public int jump(int[] nums) {
        int ans=0,currEnd=0,currLast=0;
        
        for(int i=0;i<nums.length-1;i++){
            currLast=Math.max(currLast,i+nums[i]);
            if(i==currEnd){
                ans++;
                currEnd=currLast;
            }
        }        
        return ans;
    }
}
