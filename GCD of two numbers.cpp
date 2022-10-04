#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
if(b == 0)
    return a;
return gcd(b,a%b);
}
int main() {
int a ,b ;
cin>>a>>b;
cout<<gcd(a,b);
    // you can also find the gcd by using this simple step 
    int c,d;
    cin>>c>>d;
    int ans=__gcd(a,b); // This is another method of finding the gcd of two number 
    cout<<ans<<endl;
return 0;
}
