class Solution {
public:
    void create_subsets(vector<vector<int>>& res, vector<int>& nums, int index,
                        vector<int>& current) {
        res.push_back(current);
        for (int i = index; i < nums.size(); i++) {
            current.push_back(nums[i]);
            create_subsets(res, nums, i + 1, current);
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {};
        vector<int> curr;
        create_subsets(res, nums, 0, curr);

        return res;
    }
};