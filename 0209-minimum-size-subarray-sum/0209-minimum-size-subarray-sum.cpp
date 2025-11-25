class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, total = 0, ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++){
            total += nums[i];

            while (total >= target){
                ans = min(i - l + 1, ans);
                total -= nums[l];
                l++;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};