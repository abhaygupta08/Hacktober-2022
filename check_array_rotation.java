/* 
Submitted by: sneha jaiswal
git hub link: https://github.com/Sneha-jais
You have been given an integer array/list(ARR) of size N. It has been sorted(in increasing order) and then rotated by some number 'K' in the right hand direction.
Your task is to write a function that returns the value of 'K', that means, the index from which the array/list has been rotated.
Sample Input:
1
6
5 6 1 2 3 4
Sample Output:
2
*/

public class Solution {

    public static int arrayRotateCheck(int[] arr){
    	//Your code goes here
        
        int n=arr.length;
        int x=0;
        if(n<1){
            return 0;
        }
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                x=i+1;
            break;
            }
        }
        
       if(x==n)
           x=0;
       return x; 
    }

}
