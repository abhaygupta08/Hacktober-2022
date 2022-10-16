//constraints : m<=10;n<=10

#include<iostream>
using namespace std;

void merge(int *a, int n, int *b, int m ,int c[]){
	int i=0;  int k=0;
	int j=0;
	while(i<n && j<m){
		if(a[i]<=b[j]){
			c[k]=a[i];
			k++;i++;
		}
		else{
			c[k]=b[j];
			j++; k++;
		}
	}
	while(i<n){
			c[k]=a[i];
			k++;i++;
	}
	while(j<m){
		c[k]=b[j];
			j++; k++;
	}

for(int i=0;i<n+m;i++){
	cout<<c[i]<<" ";
}

}
int main(){
	int a[]={1,3,5,9};
	int b[]={2,6,7};
	int c[20];
	
	merge(a,4,b,3,c);
}