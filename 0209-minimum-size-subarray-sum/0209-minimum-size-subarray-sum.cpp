class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int right = 0, left = 0;
        int sum = 0;
        int minimum = INT_MAX;

        while (right < n){
            sum += nums[right];
            
            while (sum >= target && left <= right){
                minimum = min(right - left + 1, minimum);
                sum -= nums[left];
                left++;
            }

            right++;
        }

        return minimum == INT_MAX ? 0 : minimum;
    }
};