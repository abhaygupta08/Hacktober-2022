// Q71 https://www.codingninjas.com/codestudio/problems/k-max-sum-combinations_975322?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website


#include<bits/stdc++.h>
using namespace std;
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    priority_queue<int> helper;
    vector<int> ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            helper.push(a[i]+b[j]);
        }}
    for(int i=0;i<k;i++){
        ans.push_back(helper.top());
        helper.pop();
    }
    
    return ans;
    
}














