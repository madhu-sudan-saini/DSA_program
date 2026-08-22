class Solution {
public:

    int solve(vector<int>& arr, int start, int end, vector<int>& dp)
    {
        if(start > end)
            return 0;

        if(start == end)
            return arr[start];

        if(dp[end] != -1)
            return dp[end];

        int incl = arr[end] + solve(arr, start, end - 2, dp);
        int excl = solve(arr, start, end - 1, dp);

        return dp[end] = max(incl, excl);
    }

    int rob(vector<int>& nums)
    {
        int n = nums.size();

        if(n == 1)
            return nums[0];

    
        vector<int> dp1(n, -1);
        int case1 = solve(nums, 1, n - 1, dp1);

        vector<int> dp2(n, -1);
        int case2 = solve(nums, 0, n - 2, dp2);

        return max(case1, case2);
    }
};
