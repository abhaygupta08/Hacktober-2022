#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int k;cin>>k;
    vector<priority_queue<int>>mx(k);
    for(int i=0;i<n;i++){
        int a;cin>>a;
        mx[i%k].push(a);
    }
    int sum=0;
    for(auto it:mx){
        sum+=it.top();
    }
    cout<<sum<<endl;
    
}
    return 0;
}
