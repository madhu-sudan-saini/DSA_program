class Solution {
public:

    void solve(vector<int>& digits,int index ,vector<int>& ans)
    {
        if(index == 3)
        {
            if(digits[2] % 2 ==0)
            {
                if(digits[0] != 0)
                {
                 int result= digits[0] * 100 +digits[1]*10 + digits[2];
                  ans.push_back(result);
                }
            }
            return;
        }
        

        for(int i=index; i< digits.size();i++)
        {
            swap(digits[index],digits[i]);

            solve(digits , index+1 , ans);

            swap(digits[index],digits[i]);
        }

    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        
        vector<int> ans;

        solve(digits,0,ans);

        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
