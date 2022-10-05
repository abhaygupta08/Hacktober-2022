#include<bits/stdc++.h>
 
using namespace std;
int main(){
 int a=0, n;
   cin>>n;
       char s[n];
    cin>>s;
    for (int i = 0; i < n; i++)
    {
        if (s[i-1]== s[i])
        {
          a++;
        }
        
    }
    cout<<a<<endl;
    
    return 0;
 
}
