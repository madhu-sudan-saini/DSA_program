#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {

        int n = s.size();

        vector<int> ans(n, INT_MAX);

        // Left to right
        int last = -1;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == c)
            {
                last = i;
            }

            if(last != -1)
            {
                ans[i] = i - last;
            }
        }

        // Right to left
        last = -1;

        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == c)
            {
                last = i;
            }

            if(last != -1)
            {
                ans[i] = min(ans[i], last - i);
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    string s;
    char c;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter character: ";
    cin >> c;

    vector<int> result = obj.shortestToChar(s, c);

    cout << "Answer: ";

    for(int x : result)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
