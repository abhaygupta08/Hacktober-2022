class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        
        vector<long long> nums3;
        
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]>nums2[j]){
                nums3.push_back(nums2[j]);
                j++;
            }
            else{
                nums3.push_back(nums1[i]);
                i++;
            }
        }
        while(i<nums1.size()){
            nums3.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            nums3.push_back(nums2[j]);
            j++;
        }
       
        double m1=nums3[nums3.size()/2.0];
        double m2=nums3[nums3.size()/2.0-1.0];
        
       if(nums3.size()%2==1){
           return m1;
       }
        else{
            return (m1+m2)/2;
        }
        
    }
};
