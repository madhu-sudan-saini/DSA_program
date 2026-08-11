#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {

        int index = -1;

        // Find the first occurrence of ch
        for(int i = 0; i < word.size(); i++)
        {
            if(word[i] == ch)
            {
                index = i;
                break;
            }
        }

        // If ch is not found
        if(index == -1)
        {
            return word;
        }

        // Reverse the prefix
        int l = 0;
        int r = index;

        while(l < r)
        {
            swap(word[l], word[r]);
            l++;
            r--;
        }

        return word;
    }
};

int main() {

    Solution obj;

    string word;
    char ch;

    cout << "Enter word: ";
    cin >> word;

    cout << "Enter character: ";
    cin >> ch;

    string result = obj.reversePrefix(word, ch);

    cout << "Result: " << result << endl;

    return 0;
}
