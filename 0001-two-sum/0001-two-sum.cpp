class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) != map.end()) {
                return vector<int>{map[nums[i]], i};
            }
            map.insert({target - nums[i], i});
        }

        return vector<int>{};
    }
};