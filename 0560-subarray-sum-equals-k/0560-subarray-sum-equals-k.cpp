class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        int curr_sum = 0, ans = 0;
        for (auto& num : nums) {
            curr_sum += num;

            if (curr_sum == k) {
                ans++;
            }

            if (mp.count(curr_sum - k)) {
                ans += mp[curr_sum - k];
            }

            if (mp.count(curr_sum) == 0) {
                mp[curr_sum] = 1;
            } else {
                mp[curr_sum] += 1;
            }
        }

        return ans;
    }
};