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
    int result = 0;
public:
    void traverse(TreeNode * root){
        if(!root)
            return;
        if(root->left)
            if(!root->left->left && !root->left->right)     // a left leaf
                result += root->left->val;
        traverse(root->left);
        traverse(root->right);
                
    }
    int sumOfLeftLeaves(TreeNode* root) {
        traverse(root);
        return result;
    }
};
