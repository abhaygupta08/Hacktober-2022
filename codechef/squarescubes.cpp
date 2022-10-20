#include<bits/stdc++.h>
using namespace std;
#define long long int;
int32_t main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int c=(int)sqrt(n)+(int)cbrt(n)-(int)sqrt(cbrt(n));
        cout<<c;

    }
    return 0;
}