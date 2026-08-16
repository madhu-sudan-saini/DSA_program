class Solution {
public:

    bool solve(vector<int>& nums, int index,
               long long prod1, long long prod2,
               long long target)
    {
        if (index == nums.size())
            return prod1 == target && prod2 == target;

        return (prod1 <= target / nums[index] &&
                solve(nums, index + 1,
                      prod1 * nums[index], prod2, target))
            ||
               (prod2 <= target / nums[index] &&
                solve(nums, index + 1,
                      prod1, prod2 * nums[index], target));
    }

    bool checkEqualPartitions(vector<int>& nums, long long target) {
        return solve(nums, 0, 1, 1, target);
    }
};
