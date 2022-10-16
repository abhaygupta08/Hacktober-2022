#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

	int arr[] = {-2, 0, -1, 2, -3, 1, 3};
	int n = sizeof(arr) / sizeof(int);
	int k = 4;

	// for first negative we have to maintain a ds which contain negatives series wise
	// so for first we use first in first out => queue
	queue<int>q;
	int j=0, i=0;

	while(j<k){
		// for window queue
		if(arr[j] < 0)
		{
			q.push(arr[j]);
		}
		j++;
	}
	cout<<q.front()<<" ";
	while(j<n){
		if(arr[i] == q.front()){
			q.pop();
		}
		i++;
		if(arr[j] < 0){
			q.push(arr[j]);
		}
			cout<<q.front()<<" ";
			j++;
	}

}