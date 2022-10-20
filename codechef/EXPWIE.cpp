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
            arr[i]=i+1;
        }
        for(int i=0;i<N;i++){
            cout<<arr[i];
        }

        T--;
    }
    return 0;
}