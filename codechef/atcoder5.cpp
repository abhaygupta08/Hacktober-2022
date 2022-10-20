#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL) ;
    int N,l,sum=0;

    cin>>N; 

    for(int i=1;i<=N;i++){
        
              l=floor(N/i);

        sum=sum+l;
    }
    cout<<sum;
    return 0;
}