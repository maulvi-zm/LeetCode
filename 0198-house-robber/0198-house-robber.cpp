class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = nums[1];

        int highest_idx = 0;

        for (int i = 2; i < nums.size(); i++) {
            highest_idx = dp[highest_idx] > dp[i - 2] ? highest_idx : i - 2;
            dp[i] = nums[i] + dp[highest_idx];
        }

        return max(dp[nums.size() - 1], dp[nums.size() - 2]);
    }
};