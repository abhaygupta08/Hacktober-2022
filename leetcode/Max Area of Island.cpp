class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n), rightMax(n);
        for (int i = 1; i < n; ++i) 
            leftMax[i] = max(height[i-1], leftMax[i-1]);
        for (int i = n-2; i >= 0; --i) 
            rightMax[i] = max(height[i+1], rightMax[i+1]);
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int waterLevel = min(leftMax[i], rightMax[i]);
            if (waterLevel >= height[i]) ans += waterLevel - height[i];
        }
        return ans;
    }
};
