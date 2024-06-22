#include <stack>
#include <string>

bool isValidParenthesis(const std::string& s)
{
    std::stack<char> t;
    for(char ch : s)
    {
        if(ch == '(' || ch == '{' || ch == '[')
        {
            t.push(ch);
        }
        else
        {
            if (!t.empty()) {
                char top = t.top();
                if ((ch == '}' && top == '{') || 
                    (ch == ')' && top == '(') ||
                    (ch == ']' && top == '['))
                {
                    t.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    return t.empty();
}
