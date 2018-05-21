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
    void invert(TreeNode* root){
        if(!root)   return;
        
        if(root->left && root->right){
            TreeNode * temp = root->left;
            root->left = root->right;
            root->right = temp;
        }else if(!root->left){
            root->left = root->right;
            root->right = NULL;
        }else if(!root->right){
            root->right = root->left;
            root->left = NULL;
        }else{
            return;
        }
        invertTree(root->left);
        invertTree(root->right);        
    }
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};
