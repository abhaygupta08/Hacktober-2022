#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin>>t;
  while(t--){
    vector<string> v;

   for(int i=0; i<8; i++){
    string s1;
    cin>>s1;
    v.push_back(s1);
   }
   int ind= 0;
   int temp=0;
   for(int j=0; j<v.size(); j++){
    int c=0;
        for(int i=0; i<8; i++){
        if(v[j][i]=='#') c++;
    }
    if(c==1 && (j!= 0 && j!= 7)&& temp==2) {
        ind= j;
        break;
    }
    temp=c;
   }

   cout<<ind+1<<" ";
   int x=0;
   for(int i=0; i<8; i++){
    if(v[ind][i]=='#') {x=i; break;}
   }
   cout<<x+1<<endl;
}
  return 0;
}
