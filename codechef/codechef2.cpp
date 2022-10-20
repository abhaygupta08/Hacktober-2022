#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,reverse=0,num;
    cout<<"number of digit";
    cin>>n;
    while(n!=0){ 
        num=n%10;
        reverse=reverse*10+num;
        n=n/10;
    }
     cout<<reverse;
    return 0;
}