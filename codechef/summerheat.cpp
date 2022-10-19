#include<bits/stdc++.h>
using namespace std;
int main(){
  int T,xa,xb,Xa,Xb;
  cin>>T;
  while(T!=0){
   cin>>xa>>xb>>Xa>>Xb;
   int a=Xa/xa;
   int b=Xb/xb;
   cout<<a+b<<'\n';
   T--;
  }
    return 0;
}