#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            if (ch == '(' || ch == '[' || ch == '{')
            {
                st.push(ch);
            }
            else
            {
                if (!st.empty())
                {
                    char top = st.top();

                    if ((ch == ')' && top == '(') ||
                        (ch == ']' && top == '[') ||
                        (ch == '}' && top == '{'))
                    {
                        st.pop();
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

        return st.empty();
    }
};

int main()
{
    Solution sol;

    string s;
    cout << "Enter a string: ";
    cin >> s;

    if (sol.isValid(s))
        cout << "String is valid";
    else
        cout << "String is not valid";

    return 0;
}
