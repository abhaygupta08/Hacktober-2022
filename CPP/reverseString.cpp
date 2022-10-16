#include <iostream>
using namespace std;
void reverseStr(string& str)
{
    int len = str.length();
    int n = len-1;
    int i = 0;
    while(i<=n){
        swap(str[i],str[n]);
        n = n-1;
        i = i+1;
  }
 
}
int main()
{
    string str = "Hacktoberfest";
    reverseStr(str);
    cout << str;
    return 0;
}