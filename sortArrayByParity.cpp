#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        vector<int> ans;

        // Add even numbers first
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % 2 == 0)
            {
                ans.push_back(nums[i]);
            }
        }

        // Add odd numbers
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % 2 != 0)
            {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> result = obj.sortArrayByParity(nums);

    cout << "Array after sorting by parity: ";

    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}
