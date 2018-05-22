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
public:
    int sumUp(TreeNode * node, int pre, int sum){
        if(!node)   return 0;
        int cur = node->val + pre;
        return (cur == sum) + sumUp(node->left, cur, sum) + sumUp(node->right, cur, sum);
    }
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        return sumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};
