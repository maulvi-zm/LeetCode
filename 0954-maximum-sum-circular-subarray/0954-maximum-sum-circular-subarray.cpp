class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMax = nums[0], currMin = nums[0], globalMax = nums[0],
            globalMin = nums[0];
        int totalSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            currMin = min(nums[i], currMin + nums[i]);
            globalMin = min(globalMin, currMin);

            currMax = max(nums[i], currMax + nums[i]);
            globalMax = max(globalMax, currMax);

            totalSum += nums[i];
        }

        if (totalSum == globalMin)
            return globalMax;

        return max(globalMax, totalSum - globalMin);
    }
};