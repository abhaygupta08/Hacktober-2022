#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T!=0){
        int N;
        cin>>N;
        int arr[N];
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }
        sort(arr, arr+N);
        cout<<arr[N-1]-arr[0]<<'\n';
        T--;
    }
    return 0;
}