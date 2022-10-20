class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
// BRUTE [T(O((n+m + (n+m)log(n+m))))] [S(O(n+m))]
        // vector<int>ans;
        // for(auto x:nums1)
        //     ans.push_back(x);
        // for(auto x:nums2)
        //     ans.push_back(x);
        // sort(ans.begin(),ans.end());
        // if(ans.size()%2==0)
        //     return (ans[ans.size()/2] + ans[ans.size()/2 -1])/2.0;
        // else return ans[ans.size()/2];
        
// OPTIMAL [T(O(min(n1 ,n2))] [S(O(1m))]
        if(nums2.size()<nums1.size()) return findMedianSortedArrays(nums2,nums1);   
        int n1=nums1.size(),n2=nums2.size();
        int low=0,high=n1;
        while(low<=high)
        {
            int cut1=(low+high)/2;
            int cut2=(n1+n2+1)/2-cut1;
            
            int left1= cut1==0 ? INT_MIN : nums1[cut1-1];
            int left2= cut2==0 ? INT_MIN : nums2[cut2-1];

            int right1= cut1==n1 ? INT_MAX : nums1[cut1];
            int right2= cut2==n2 ? INT_MAX : nums2[cut2];

            if(left1<=right2 && left2<=right1)
            {
                if((n1+n2)%2==0)
                    return (max(left1,left2) + min(right1,right2) )/ 2.0;
                else
                    return max(left1,left2);
            }
            else if(left1>right2)
                high=cut1-1;
            else
                low=cut1+1;
        }
        return 0.0;
    }
};

//Contributed by @debugagrawal
