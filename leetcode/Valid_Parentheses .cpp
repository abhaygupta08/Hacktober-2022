#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string str)
    {
        stack<char> stack;

        for (const char c : str)
            if (c == '(')
                stack.push(')');
            else if (c == '{')
                stack.push('}');
            else if (c == '[')
                stack.push(']');
            else if (stack.empty() || pop(stack) != c)
                return false;

        return stack.empty();
    }

private:
    int pop(stack<char> &stack)
    {
        const int c = stack.top();
        stack.pop();
        return c;
    }
};