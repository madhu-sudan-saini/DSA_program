#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {

        int l = 0;
        int r = s.size() - 1;

        while(l < r)
        {
            // Left character is not a letter
            if(!isalpha(s[l]))
            {
                l++;
                continue;
            }

            // Right character is not a letter
            if(!isalpha(s[r]))
            {
                r--;
                continue;
            }

            // Both characters are letters
            swap(s[l], s[r]);

            l++;
            r--;
        }

        return s;
    }
};

int main()
{
    Solution obj;

    string s;

    cout << "Enter string: ";
    getline(cin, s);

    string result = obj.reverseOnlyLetters(s);

    cout << "Result: " << result << endl;

    return 0;
}
