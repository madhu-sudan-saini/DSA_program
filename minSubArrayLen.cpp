class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left = 0;
        int sum = 0;
        int minRange = INT_MAX;

        for(int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];

            while(sum >= target)
            {
                minRange = min(minRange, right - left + 1);

                sum -= nums[left];
                left++;
            }
        }

        if(minRange == INT_MAX)
            return 0;

        return minRange;
    }
};
