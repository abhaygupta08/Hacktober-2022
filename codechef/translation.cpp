#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t,str1;
    cin>>s>>t;
    reverse(t.begin(),t.end());
    if(t==s){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}