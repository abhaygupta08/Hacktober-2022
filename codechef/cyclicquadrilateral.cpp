#include<bits/stdc++.h>
using namespace std;
int main(){
 int T,A,B,C,D;
 cin>>T;
 while(T!=0){
     cin>>A>>B>>C>>D;
     if(A+C==180){
         cout<<"YES"<<'\n';
     }
     else{
         cout<<"NO"<<'\n';
     }
     T--;
 }
     return 0;
}