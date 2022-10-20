// Make All Odd
// Problem Description:
/*
You are given an array of n integers. You want to make all the numbers in this array as odd. 
In one operation you can select two indices i and j (i≠j) and replace ai with (ai+aj).
Find the minimum number of operations needed to make all the numbers odd. If there is no way to do it, then print −1.
*/

// Test Cases:
/*
Input:
4
4
1 4 3 2
5
1 4 3 2 5
6
1 2 6 5 3 4
3
4 2 6

Output:
2
2
3
-1
*/

// Implementation:
#include <bits/stdc++.h>

using namespace std;

int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       int arr[n];
       int val=0;
       for(int i=0;i<n;i++)
       {
           cin>>arr[i];
       }
       for(int j=0;j<n;j++)
       {
           if(arr[j]%2==0)
             val++;
       }
       if(val!=n)
       cout<<val<<"\n";
       else
       cout<<"-1\n";
   }
   
   return 0;
}
