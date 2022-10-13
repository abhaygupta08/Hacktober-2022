#include<bits/stdc++.h>
#define int long long
using namespace std;

void solution(){
    int a,b,c;
    cin>>a>>b>>c;
    int ans=abs(b-c)+c;
    // cout<<ans<<endl;
    if(a<ans) cout<<1<<endl;
    else if(a>ans) cout<<2<<endl;
    else cout<<3<<endl;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        solution();
    }
    return 0;
}
