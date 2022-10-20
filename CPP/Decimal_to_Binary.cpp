#include<bits/stdc++.h>
using namespace std;

int decimaltobinary(int n)
{ 
    int answer = 0;
    int p = 1;
    // converting the base to 10.....==> concept
while(n>0)
{
answer += (n&1) *p;
p*=10;
n = n>>1;

}

return answer;
}

int main() {


int n ;

cin>> n;

cout<<decimaltobinary(n)<<endl;
return 0;

}
