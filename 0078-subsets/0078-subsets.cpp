class Solution {
public:
    void create_subsets(vector<vector<int>>& res, vector<int>& nums, int index,
                        vector<int> current) {
        for (int i = index; i < nums.size(); i++) {
            vector<int> copy = current;
            copy.push_back(nums[i]);
            res.push_back(copy);

            create_subsets(res, nums, i + 1, copy);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {};
        res.push_back(vector<int>{});
        create_subsets(res, nums, 0, vector<int>{});

        return res;
    }
};