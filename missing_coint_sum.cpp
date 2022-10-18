#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){


int n;
cin>>n;
vector<int>vec(n);
for(int i=0;i<n;i++){
cin>>vec[i];
}
sort(vec.begin(),vec.end());
int ans=1;
for(int i=0;i<n&&(vec[i]<=ans);i++){
ans=ans+vec[i];
}

cout<<ans;





}