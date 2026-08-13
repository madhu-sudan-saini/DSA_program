class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++)
        {
            int greater = -1;

            for(int j = 1; j < nums.size(); j++)
            {
                int index = (i + j) % nums.size();

                if(nums[index] > nums[i])
                {
                    greater = nums[index];
                    break;
                }
            }

            ans.push_back(greater);
        }

        return ans;
    }
};
