#include<bits/stdc++.h>
using namespace std;
int main(){
    int T,n;
    string str;
    cin>>T;
    while(T!=0){
        cin>>str;
        n=str.size();
        for(int i=0;i<n;i++){
            if(str[i]==str[n-i-1]){
                continue;
                cout<<"wins"<<'\n';
            }
            else{
                cout<<"loses"<<'\n';
            }
        }
     T--;
    }
  return 0;
}
