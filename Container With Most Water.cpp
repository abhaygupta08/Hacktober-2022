class Solution {
public:
    int maxArea(vector<int>& height) {
        int m=height.size();
        int temp=0,rem=0;
        int f=0,l=m-1;
        while(f!=l)
        {
            if(height[f]<height[l])
               {
                   temp=height[f]*(l-f);
                       f++;
                   if(temp>rem)
                   {
                       rem=temp;
                   }
               }
            else
               {
                   temp=height[l]*(l-f);
                       l--;
                   if(temp>rem)
                   {
                       rem=temp;
                   }
               }
        }
        return rem;
    }
};
