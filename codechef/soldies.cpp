#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,n,w;
    cin>>k>>n>>w;
    int s=w*(w+1)/2;
    cout<<(k*s)-n;
    return 0;
}