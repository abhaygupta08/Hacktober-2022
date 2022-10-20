#include<bits/stdc++.h>
using namespace std;
int main(){
    string str1,str2,ch1,ch2;
    cin>>str1;
    cin>>str2;
    for(int i=0;i<str1.size();i++){
        ch1= tolower(str1[i]);
        ch2= tolower(str2[i]);
    }
    if(ch1<ch2){
     cout<<"-1";
    }
    else if(ch2==ch1){
        cout<<"0";
    }
    else{
        cout<<"1";
    }

    return 0;
}