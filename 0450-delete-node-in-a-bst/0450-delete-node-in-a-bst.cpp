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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key == root->val){
            TreeNode* left = root->left;
            TreeNode* right = root->right;

            root = nullptr;
            if (right){
                root = new TreeNode(findMinAndDelete(right));
                root->right = right;
                root->left = left;
            } else if (left) {
                root = new TreeNode(findMaxAndDelete(left));
                root->right = right;
                root->left = left;
            } 

        }

        return root;
    }
private:
    int findMaxAndDelete(TreeNode*& root){
        if (root->right) {
            return findMaxAndDelete(root->right);
        }

        int val = root->val;
        root = root->left;
        
        return val;
    }

    int findMinAndDelete(TreeNode*& root){
        if (root->left){
            return findMinAndDelete(root->left);
        }

        int val = root->val;
        root = root->right;

        return val;
    }
};