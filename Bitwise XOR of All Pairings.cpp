// Bitwise XOR of All Pairings
// leetcode

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int XOR=0;
        int n=nums1.size();
        int m=nums2.size();
        vector<long long> fr(32, 0);

        for(auto it : nums1)
        {
            for(int j=0; j<32; j++)
            {
                if(it&(1ll<<j))
                {
                    fr[j]+=m;
                }
            }
        }

        for(auto it : nums2)
        {
             for(int j=0; j<32; j++)
            {
                if(it&(1ll<<j))
                {
                    fr[j]+=n;
                }
            }
        }

        for(int i=0; i<32; i++)
        {
            if(fr[i]&1)
            {
                XOR|=(1ll<<i);
            }
        }
        return XOR;
    }
};
