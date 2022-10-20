//problem statement
//Printing spiral matrix


#include<iostream>
using namespace std;
void printspiral(int arr[][3],int n,int m){
    int count=0;
    int startrow=0;
    int startcol=0;
    int endrow=n;
    int endcol=m;
    int total=n*m;
    while (count<total)
    {
        for (int i = startcol; i <endcol && count<=total; i++)
        {
           cout<<arr[startrow][i]<<" ";
           count++;
        }
        startrow++;
        for (int i = startrow; i < endrow && count<=total; i++)
        {
            cout<<arr[i][endcol-1]<<" ";
            count++;
        }
        endcol--;
        for (int i = endcol-1; i >=startcol && count<=total; i--)
        {
            cout<< arr[endrow-1][i]<<" ";
            count++;
        }
        endrow--;
        for (int i = startcol; i < endcol && count<=total; i++)
        {
            cout<<arr[endrow-1][i]<<" ";
            count++;
        } 
    }
}
int main(){
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    printspiral(arr,3,3);
return 0;
}