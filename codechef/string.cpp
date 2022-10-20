#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        string str,str1,str2;
        cin>>str;
        int n=str.size();
        if(n%2!=0){
            cout<<"NO"<<'\n';
        }
        else{
          str1=str.substr(0,n/2);
          str2=str.substr(n/2,n);
            if(str1==str2){
                cout<<"YES"<<'\n';
            }
            else{
                cout<<"NO"<<'\n';
            }
        }
    }
    return 0;
}