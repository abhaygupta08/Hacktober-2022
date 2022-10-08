//https://www.codingninjas.com/codestudio/problems/615?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h> 
long long merge(long long input[],long long t[], long long si,long long mid, long long ei){

    long long i=si,j=mid+1,k=si, ic=0;
    while(i<=mid && j<=ei){
        if(input[i]<=input[j]){
            t[k++]=input[i++];
        }
        else{
            t[k++]=input[j++];
            ic=ic+(mid-i+1);
        }
    }
    while(i<=mid){
         t[k++]=input[i++];        
    }
     while(j<=ei){
         t[k++]=input[j++];
    }
    for(i=si;i<=ei;i++)
        input[i]=t[i];
    return ic;

}

long long sort(long long input[], long long t[], long long si, long long ei){
    long long mid, ic=0;
    if(si<ei){
        mid=(si+ei)/2;
        ic+=sort(input,t,si,mid);
        ic+=sort(input,t,mid+1,ei);
        ic+=merge(input,t,si,mid,ei);
    }
    return ic;
}


long long getInversions(long long *input, long long size){
    // Write your code here.
        long long si=0, ei=size-1;
    long long t[size];
        return sort(input,t,si,ei);  

}
