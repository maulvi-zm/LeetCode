/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        stack<pair<TreeNode*, int>> dfs;
        pair<TreeNode*, int> curr;
        int currentSum = 0;

        dfs.push({root, root->val});
        while (!dfs.empty()){
            curr = dfs.top();
            dfs.pop();

            TreeNode* left = curr.first->left;
            TreeNode* right = curr.first->right;
            if (left){

                dfs.push({left, curr.second + left->val});
            } 

            if (right){
                dfs.push({right, curr.second + right->val});
            }

            if (!left && !right){
                if (curr.second == targetSum) return true;
            }
        }

        return false;
    }
};




