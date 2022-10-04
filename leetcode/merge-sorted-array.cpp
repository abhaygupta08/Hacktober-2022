#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &num1, int m, vector<int> &num2, int n)
    {
        int i = m + n;
        while (m > 0 && n > 0)
        {
            if (num1[m - 1] > num2[n - 1])
            {
                num1[i - 1] = num1[m - 1];
                --m;
            }
            else
            {
                num1[i - 1] = num2[n - 1];
                --n;
            }
            --i;
        }

        while (n > 0)
        {
            num1[i - 1] = num2[n - 1];
            --n;
            --i;
        }
    }
};