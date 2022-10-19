#include<bits/stdc++.h>
using namespace std;
int main(){
    string str,ch;
    cin>>str;
    int c=0,s=0;
    for(int i=0;i<str.size();i++){
      if(str[i]>=65 && str[i]<=90){
          c++;
      }
      else{
          s++;
      }}
      cout<<s;
      if(c>s)
      for (int i = 0; i < str.size(); i++) {
    ch = toupper(str[i]);

    cout << ch;
  }
  else{
      for (int i = 0; i < str.size(); i++) {

    // convert str[i] to uppercase
    ch = tolower(str[i]);

    cout << ch;
  }
  }
    return 0;
}