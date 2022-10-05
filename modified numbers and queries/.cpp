class Solution {
  public:
    int sumOfAll(int l, int r){
        
        vector<int>v(r+1,0);
        v[1]=1;
        
        for(int i=2;i<=r;i++)
        {
         if(v[i]==0)      // v[i]=0  -> v[i]=i
         {  
         for(int j=i;j<=r;j+=i)  // for the summation of vector
         {
             v[j]+=i;
         }
         }
        }
         int s=0;
         for(int i=l;i<=r;i++)
         {
             s+=v[i];
             
         }
         return s;
         
        }
        // code here
    
};
