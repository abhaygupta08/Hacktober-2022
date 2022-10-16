#include<iostream>
#include<queue>
using namespace std;
int main(){
	int arr[] = {1, 4, 0, 1, 2, 3, 5};
	int n = sizeof(arr) / sizeof(int);
	int k = 4;

	int i=0, j=0;
	vector<int>v;
	deque<int>dq;
	while(j<k){
		if(!dq.empty() && dq.back()<arr[j]){
			dq.pop_back();
		}
		dq.push_back(arr[j]);
		j++;
	}
	v.push_back(dq.front()); // the front element is greatest for the kth window
	while(j<n){
		if(dq.front()==arr[i]){
			dq.pop_front();
		}
		i++;
		if(!dq.empty() && dq.back()<arr[j]){
			dq.pop_back();
		}
		dq.push_back(arr[j]);
		j++;
		v.push_back(dq.front());
	}
	for(auto it:v){
		cout<<it<<" ";
	}
	return 0;
}