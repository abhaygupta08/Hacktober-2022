#include<bits/stdc++.h>
using namespace std;
int main(){
    int T,n,p,q,r,s,t,u,v,w,x;
    cin>>T;
    while (T!=0)
    {
        cin>>n;
        p=n/100;
        r=n%100;
        q=r/50;
        s=r%50;
        t=s/10;
        u=s%10;
        v=u/2;
        w=u%2;
        x=w/1;
        cout<<p+q+t+v+x<<'\n';
        T--;
    }
    
    return 0;
}