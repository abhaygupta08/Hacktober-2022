#include<bits/stdc++.h>
using namespace std;
int main(){
    int T,p,q,count=0;
    cin>>T;
    while(T--){
        cin>>p>>q;
        if(q-p>=2){
            count++;
        }
    }
    cout<<count;
    return 0;
}