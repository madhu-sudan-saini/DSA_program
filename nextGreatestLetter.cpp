class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int start = 0;

        while(start < letters.size())
        {
            if(letters[start] > target)
            {
                return letters[start];
            }

            start++;
        }

        return letters[0];
    }
};
