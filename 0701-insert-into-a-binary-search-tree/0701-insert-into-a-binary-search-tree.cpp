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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) root = new TreeNode(val);
        else insertHelper(root, val);

        return root;
    }

private:
    void insertHelper(TreeNode* root, int val){
        if (!root->left && root->val > val) root->left = new TreeNode(val);
        else if (!root->right && root->val < val) root->right = new TreeNode(val);
        else {
            if (val > root->val) insertIntoBST(root->right, val);
            else insertIntoBST(root->left, val);
        }
    }
};