
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
int t;
cin>>t;
while(t--){
string a, b;
cin>>a>>b;
int counta=0;
int countb=0;
int n=a.length();
int m=b.length();

if(a[n-1]=='L'&&(b[m-1]!='L')){
    cout<<">"<<endl;
}
else if(a[n-1]=='S'&&b[m-1]!='S'){
    cout<<"<"<<endl;
}
else if(a[n-1]!='L'&&(b[m-1]=='L')){
    cout<<"<"<<endl;
}
else if(a[n-1]!='S'&&b[m-1]=='S'){
    cout<<">"<<endl;
}
else if(a==b)cout<<"="<<endl;
else if(a[n-1]==b[m-1]){
    if(a[n-1]=='S'){
        if(n>m){
            cout<<"<"<<endl;
        }
        else{
            cout<<">"<<endl;
        }
        }

    

    else if(a[n-1]=='L'){
        if(n>m){
            cout<<">"<<endl;
        }
        else{
            cout<<"<"<<endl;
        }
        }

    }
}
}
