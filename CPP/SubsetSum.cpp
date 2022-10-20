// Q49 https://www.codingninjas.com/codestudio/problems/subset-sum_3843086?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: 
// recursion + sorting 
// O(2^n+2^nlog(2^n))

// Space: 2^n

#include <algorithm>
void recf(int ind,int sum, vector<int> &num, int n, vector<int> &r){
    if(n==ind){
        r.push_back(sum);
        return;
    }    
    recf(ind+1,sum+num[ind],num,n,r);
    recf(ind+1,sum,num,n,r);
}

vector<int> subsetSum(vector<int> &num){
    vector<int> r;
    recf(0, 0, num, num.size(),r);
    sort(r.begin(),r.end());
    return r;
}
