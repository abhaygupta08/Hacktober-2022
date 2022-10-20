#include <bits/stdc++.h>
using namespace std;

int lucky_number(int n)
{

int ans = 0;

int count_digits=0;

int num = n;

while(n>0)
{
    n = n/10;
    count_digits++;
}

// cout<<count_digits<<endl;

for(int i = 1 ; i <count_digits ;i++)
{
    ans+= (1<<i);
}

int pos = 0;

int last_digit;

while(num>0)
{
  last_digit = num%10;
  if(last_digit == 7)
  {
      ans+= (1<<pos);
      
  }
  pos++;
  num = num/10;
}


return ans+1;



}

int main() {

int n;

cin>>n;

cout<<lucky_number(n)<<endl;


return 0;
}
