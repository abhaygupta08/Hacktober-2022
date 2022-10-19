#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    int arr[str.size()];
    for(int i=0;i<(str.size()/2)/2+1; i++){
         arr[i]=str[2*i];
    }
    sort(arr,arr+str.size());
    cout<<arr[1];
    return 0;
}