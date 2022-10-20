#include<bits/stdc++.h>
using namespace std;
#define long long int;
int32_t main(){
    int T;
    cin>>T;
    while(T--){
        int A,B;
        cin>>A>>B;
        int gcd=__gcd(A,B);
        int lcm=(A/__gcd(A,B))*B;
        cout<<gcd<<' '<<lcm<<'\n';
    }
    return 0;
}