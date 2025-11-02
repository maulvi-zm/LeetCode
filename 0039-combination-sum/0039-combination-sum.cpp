class Solution {
public:
    bool dfs(vector<vector<int>>& res, vector<int>& candidates,
             vector<int>& curr, int target, int idx) {
        if (std::accumulate(curr.begin(), curr.end(), 0) > target) {
            return false;
        }

        if (std::accumulate(curr.begin(), curr.end(), 0) == target) {
            res.push_back(curr);
            return true;
        }

        for (int i = idx; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            dfs(res, candidates, curr, target, i);
            curr.pop_back();
        }

        return true;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr ;

        dfs(res, candidates, curr, target, 0);

        return res;
    }
};