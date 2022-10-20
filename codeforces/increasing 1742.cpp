#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        bool b=1;
        sort(a,a+n);
        for(int i=0;i<n-1;i++){
            if(a[i]==a[i+1]){
                b=0;
                break;
            }
        }
        if(b==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
