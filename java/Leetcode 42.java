/*
Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

https://leetcode.com/problems/trapping-rain-water/
*/

class Solution {
   public int trap(int[] heights) {
        int n=heights.length;
        int[] maxr=new int[n];
        int[] maxl=new int[n];
        
        maxl[0]=heights[0];
        for(int i=1;i<n;i++)
            maxl[i]=Math.max(heights[i],maxl[i-1]);
        
        maxr[n-1]=heights[n-1];
        for(int i=n-2;i>=0;i--)
            maxr[i]=Math.max(maxr[i+1],heights[i]);
        
        int[] ans=new int[n];
        int sum=0;
        for(int i=0;i<n;i++){
            ans[i]=Math.min(maxl[i],maxr[i])-heights[i];
            sum+=ans[i];
        }
        
        return sum;
    }
}
