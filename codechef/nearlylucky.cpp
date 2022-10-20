#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    int count=0;
    cin>>str;
    for(int i=0;i<str.size();i++){
        if(str[i]=='4' || str[i]=='7'){
            count++;
        }
    }
    if(count==str.size()){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}