class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& candidates,
             vector<int>& curr, int target, int idx, int currSum) {
        if (currSum > target) {
            return;
        }

        if (currSum == target) {
            res.push_back(curr);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            dfs(res, candidates, curr, target, i, currSum + candidates[i]);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr ;

        dfs(res, candidates, curr, target, 0, 0);

        return res;
    }
};