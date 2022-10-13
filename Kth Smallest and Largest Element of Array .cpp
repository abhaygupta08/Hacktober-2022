#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    int a[n];
    cout << "\n Enter the elements of the array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cout << "\n Enter the kth element of the array : ";
    cin >> k;
    sort(a, a + n);
    if (k >= n)
    {
        cout << "Please enter a kth element smaller than the size of the array  ";
    }
    else
    {
        cout << k << "th smallest element : " << a[k - 1] << "\n";
        cout << k << "th largest element : " << a[n - k] << "\n";
    }
}