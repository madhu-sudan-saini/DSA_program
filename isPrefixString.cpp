#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {

        string ans = "";

        for(int i = 0; i < words.size(); i++)
        {
            ans += words[i];

            if(s == ans)
            {
                return true;
            }

            // If ans becomes longer than s,
            // it can never become equal later.
            if(ans.size() > s.size())
            {
                return false;
            }
        }

        return false;
    }
};

int main()
{
    Solution obj;

    string s;
    int n;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter number of words: ";
    cin >> n;

    vector<string> words(n);

    cout << "Enter words:" << endl;

    for(int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    bool result = obj.isPrefixString(s, words);

    if(result)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
