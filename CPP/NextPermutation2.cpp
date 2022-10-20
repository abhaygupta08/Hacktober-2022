// https://leetcode.com/problems/next-permutation/submissions/

class Solution
{
public:
    void nextPermutation(vector<int> &a)
    {
        int i, j;
        int s = a.size();
        for (i = s - 2; i >= 0; i--)
        {
            if (a[i] < a[i + 1])
            {
                break;
            }
        }
        if (i < 0)
        {
            reverse(a.begin(), a.end());
        }
        else
        {
            for (j = s - 1; j >= 0; j--)
            {
                if (a[j] > a[i])
                {
                    break;
                }
            }
            swap(a[i], a[j]);
            reverse(a.begin() + i + 1, a.end());
        }
        // int x=i+1;
        // int y=s-1;
        // while(y>x){
        //     swap(a[x],a[y]);
        //     x++;
        //     y--;
        // }
    }
};
