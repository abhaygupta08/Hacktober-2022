#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &v, int k)
    {
        priority_queue<int> k1;
        for (auto x : v)
            k1.push(x);

        k--;

        while (k--)
            k1.pop();

        return k1.top();
    }
};