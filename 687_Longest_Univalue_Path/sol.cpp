/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int m = 0;
public:
    int helper(TreeNode * root){
        if(!root->left && !root->right){
            return 0;
        }
        int result = 0;
        int r = 0;
        if(root->left){
            int left = helper(root->left);
            if(root->val == root->left->val) {
                result += (left + 1);
                r = max(r, left + 1);
            }
        }
        if(root->right){
            int right = helper(root->right);
            if(root->val == root->right->val) {
                result += (right + 1);
                r = max(r, right + 1);
            }
        }
        m = max(m, result);
        return r;
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root)   return 0;
        helper(root);
        return m;
    }
};
