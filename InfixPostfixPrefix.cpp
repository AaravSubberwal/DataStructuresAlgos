#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prefixEval(string s)
{
    stack<int> st;
    int op1, op2;
    for (int i = s.length() - 1; i >= 0; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            op1 = st.top();
            st.pop();
            op2 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            default:
                break;
            }
        }
    }
    return st.top();
}

int infiixEval(string s)
{
    stack<int> st;
    int op1, op2;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            op1 = st.top();
            st.pop();
            op2 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            default:
                break;
            }
        }
    }
    return st.top();
}

int precendance(char s)
{
    if (s == '^')
    {
        return 3;
    }
    else if (s == '*' || s == '/')
    {
        return 2;
    }
    else if (s == '+' || s == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infix_postfox(string s)
{
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            result += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && precendance(st.top()) > precendance(s[i]))
            {
                result += st.top();
                st.pop();
            }
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}
