#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
int n,x;
cin>>n>>x;
vector<int>vec(n);
for(int i=0;i<n;i++)
{
    cin>>vec[i];

}

map<int,int>mp;
for(int i=0;i<n;i++){
if(mp.count(x-vec[i])!=0){
cout<<i+1<<" "<<mp[x-vec[i]]<<endl;
return 0;
}
mp[vec[i]]=i+1;
}
cout<<"IMPOSSIBLE"<<endl;

}