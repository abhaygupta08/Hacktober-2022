#include <bits/stdc++.h>

using namespace std;

void create1d(int arr[], int &n){
    cout << "How many elements do you want to store in your array: ";
    cin >> n;
    for (int i = 0; i < n; i++){
        cout << "a[" << i << "]: ";
        cin >> arr[i];
    }
}

void printa(int a[], int n){
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void bubblesort(int arr[], int n){
    
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if ( arr[j] > arr[j+1] )
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }    
}

void insertionsort(int arr[], int n){

    for (int i = 0; i <= n-1; i++)
    {
        int key = arr[i];
        
        int j = i-1;
        while ( j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }

        arr[j+1] = key;
    }
}

void selectsort(int arr[], int n)
{

    for ( int i = 0; i < n-1; i++)
    {
        int min_idx = i;

        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        
        swap(arr[i], arr[min_idx]);        
    }   
}

int main(){

    char ans;

    do{

        int arr[100], n, op;

        cout << "\t\tSORTING ARRAYS\n";

        cout << "1. Create Array\n";
        cout << "2. Bubble Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Selection Sort\n";

        cout << "Choose your option: ";
        cin >> op;

        switch (op) {
            case 1 : cout << "\tCreating Array\n";
                    create1d (arr, n);
                    cout << "You array is :\n";
                    printa (arr, n);
                    break;

            case 2 : cout << "\tBubble Sort\n";
                    bubblesort (arr, n);
                    cout << "Your sorted array is: \n";
                    printa (arr, n);
                    break;

            case 3 : cout << "\tInsertion Sort\n";
                    insertionsort (arr, n);
                    cout << "Your sorted array is: \n";
                    printa (arr, n);
                    break;

            case 4 : cout << "\tSelection Sort\n";
                    selectsort (arr, n);
                    cout << "Your sorted array is: \n";
                    printa (arr, n);
                    break; 

            default : cout << "Wrong Option! Try Again.";
        }

        cout << "Do you want to continue(Y/N): ";
        cin >> ans; 
    
    } while (ans == 'y' || ans == 'Y');

    cout << "Thank You!"; 

    return 0;
}