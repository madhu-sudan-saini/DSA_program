class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

       string result = ""; 
        for(int i=0;i<=n;i++)
        {
            char ch = strs[0][i];

            for(int j=1;j<n;j++)
            {
                if(strs[j][i] != ch)
                {
                    return result;
                }
            }
            result=result+ch;
        }
        return result;
    }
};
