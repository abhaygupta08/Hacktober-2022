#include <bits/stdc++.h>
using namespace std;

int main()
{

    //input size of array

    cout<<"ENTER SIZE OF ARRAY : "<<endl;
    int n;
    cin>>n;

    //input elements of array

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    int j = 0;
    for (int i = 0; i < n; i++) {
        //check if element of arr is not 0
        if (arr[i] != 0) {
            swap(arr[j], arr[i]); // Partitioning the array
            j++;
        }
    }
    cout<<endl;

    //print resulted array
    cout<<"Resulted array is : "<<endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Print the array
    }
 
    return 0;
}