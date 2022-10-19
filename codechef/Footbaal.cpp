#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    for(int x=0;x<str.size();x++){
    if(str[x]&str[x+1]&str[x+2]&str[x+3]&str[x+4]&str[x+5]&str[x+6]==true){
        cout<<"YES";
    }
    continue;
if(str[x]&str[x+1]&str[x+2]&str[x+3]&str[x+4]&str[x+5]&str[x+6]==false){
    cout<<"NO";
    }
}
    return 0;}
