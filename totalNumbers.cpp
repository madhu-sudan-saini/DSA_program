class Solution {
public:

    void solve(vector<int>& digits,int index ,set<int>& s)
    {
        if(index == 3)
        {
            if(digits[2] % 2 ==0)
            {
                if(digits[0] != 0)
                {
                 int result= digits[0] * 100 +digits[1]*10 + digits[2];
                  s.insert(result);
                }
            }
            return;
        }
        

        for(int i=index; i< digits.size();i++)
        {
            swap(digits[index],digits[i]);

            solve(digits , index+1 , s);

            swap(digits[index],digits[i]);
        }

    }

    int totalNumbers(vector<int>& digits) {
        set<int> s;
        solve(digits,0,s);

        return s.size();
        
    }
};
