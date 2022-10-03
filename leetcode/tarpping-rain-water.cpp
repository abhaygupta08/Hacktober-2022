//problem statement //https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    
    int trap(vector<int>& ht) {
        int n=ht.size();
        
//optimal solution Time:O(n) Space:O(1);
//         int ml=0,mr=0;
//         int l=0,r=n-1,res=0;
//         while(l<=r){
//             if(ht[l]<=ht[r]){
//                 if(ht[l]>=ml) ml=ht[l];
//                 else res+=ml-ht[l];
                
//                 l++;
//             }else{
//                 if(ht[r]>=mr) mr=ht[r];
//                 else res+=mr-ht[r];
                
//                 r--;
//             }
//         }
//         return res;
//solution with both Time & Space :O(n)
        vector<int>lm(n,0);
        vector<int>rm(n,0);
        int mx=0;
        for(int i=0;i<n;i++){
            lm[i]=max(mx,ht[i]);
            mx=max(mx,ht[i]);
        }
        mx=0;
        for(int i=n-1;i>=0;i--){
            rm[i]=max(mx,ht[i]);
            mx=max(mx,ht[i]);
        }
        mx=0;
        for(int i=0;i<n;i++){
            mx+=min(lm[i],rm[i])-ht[i];
        }
        return mx;
    }
};
