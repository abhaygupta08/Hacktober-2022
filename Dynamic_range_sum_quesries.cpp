

#include<bits/stdc++.h>
using namespace std;
#define int long long
// #define mod 99824435
const int N=2e5;
int feed[N];
int arr[N];
void upd(int x, int v,int n,int* blocks,int*nums) {
    int block_sz=ceil(sqrt(n)) ;// O(1) update
	blocks[x / block_sz] -= nums[x];
	nums[x] = v;
	blocks[x / block_sz] += nums[x];
}
int query(int l,int r,int n,int feed[],int arr[]){
    int mn=0;
    int blocksize=ceil(sqrt(n));
    while(l<r&&(l%blocksize!=0)&&(l!=0)){   
        mn=mn+arr[l];
        l++;
    }
    while(l+blocksize-1<=r){
        
            mn=mn+feed[l/blocksize];
        
        l=l+blocksize;
    }
    while(l<=r)
    {
        
        mn=mn+arr[l]   ;
             l++;
    }
    return mn;
}
void makefeed(int input[],int n,int arr[],int feed[]){
    int feedpoint=-1;
    int blocksize=ceil(sqrt(n));
    for(int i=0;i<n;i++){
        arr[i]=input[i];
        if(i%blocksize==0){
            feedpoint++;
            feed[feedpoint]=arr[i];
        }else
        feed[feedpoint]=feed[feedpoint]+arr[i];
    }
}


int prefix[N];
int32_t main(){
int n,q;
cin>>n>>q;
int vec[n];
for(int i=0;i<n;i++)
{
    cin>>vec[i];
}

 makefeed(vec,n,arr,feed);

while(q--){
    int  a,l,r;
    cin>>a>>l>>r;
    if(a==1){
upd(l-1,r,n,feed,vec);
    }
    else{
cout<<query(l-1,r-1,n,feed,arr)<<endl;
    }
}



}