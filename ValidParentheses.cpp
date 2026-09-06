#include <iostream>
#include <string>
#include <stack>

using namespace std;


class Solution {
    public:
        bool isValid(string s);
};


bool Solution::isValid(string s)
{
    std::stack<char> _stack;
    for(size_t i = 0; i < s.size(); i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            _stack.push(s[i]);
        else
        {
            if(_stack.empty())
                return false;

            char first = _stack.top();
            if((first == '(' && s[i] != ')') || (first == '{' && s[i] != '}') || (first == '[' && s[i] != ']'))
                return false;
            _stack.pop();
        }
    }
    return _stack.empty();
}

