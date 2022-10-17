
//User function Template for Java

class Solution
{ 
    public static int findSum(int arr[],int n) 
    {
        //code here
        // if(n==1){
            
        // }
        int mx= Integer.MIN_VALUE, mn= Integer.MAX_VALUE;
        for(int i=0;i<n; i++){
            mx= Math.max(mx, arr[i]);
            mn= Math.min(mn, arr[i]);
        }
        
        return mn + mx;
    }
}