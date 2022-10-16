#include<iostream>
#include<queue>
using namespace std;
int main(){
	int arr[] = {-2, 0, -1, 2, -3, 1, 3};
	int n = sizeof(arr) / sizeof(int);
	int k = 4;

	int i=0,j=0;
	// for first negative we push all negative in the queue as it works on first in first out
	deque<int>q;
	while(j<k){
		if(arr[j] < 0){
			q.push_back(arr[j]);
		}
		j++;
	}
	cout<<q.front()<<" ";
	while(j<n){
		if(arr[i]==q.front()){
			q.pop_front();
		}
		i++;
		if(arr[j] < 0){
			q.push_back(arr[j]);
		}
		j++;
		cout<<q.front()<<" ";
	}
	return 0;
}