// https://leetcode.com/problems/reverse-pairs/

// O(nlog(n))
class Solution {
public:
    
    int merge(vector<int> &n,int si, int mid, int ei){
        int c=0;
        int j=mid+1;
        for(int i=si;i<=mid;i++){
            while(j<=ei&& n[i]>2LL*n[j]){
                j++;
            }
            c+=(j-(mid+1));
        }
        
        vector<int> t;
        int l=si,r=mid+1;
        while(l<=mid&&r<=ei){
            if(n[l]<n[r]){
                t.push_back(n[l]);
                l++;
            }
            else{
                t.push_back(n[r]);
                r++;
            }
        }
        while(l<=mid){
            t.push_back(n[l++]);
        }
        while(r<=ei){
            t.push_back(n[r++]);
        }
        for(int i=si;i<=ei;i++){
            n[i]=t[i-si];
        }
        return c;
    }
    
    int msort(vector<int> &n, int si, int ei){
        if(si>=ei)
            return 0;
        int mid=(si+ei)/2;
        int rp=0;
        rp+=msort(n,si,mid);
        rp+=msort(n,mid+1,ei);
        rp+=merge(n,si,mid,ei);
        return rp;

    }
    int reversePairs(vector<int>& n) {
        return  msort(n,0,n.size()-1);
    }
};




// O(n*n)

class Solution {
public:
    int reversePairs(vector<int>& n) {
        int s=n.size(),c=0;
        for(int i=0;i<s;i++){
            for(int j=i+1;j<s;j++){
                long long p=n[i];
                long long q=(long long)n[j]*2; // 2147483647*2 canot store in int
                if(p>q) c++;
            }
        }
        return c;
    }
};
