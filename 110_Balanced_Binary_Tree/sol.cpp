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
    int height(TreeNode * root){
        if(!root)
            return 0; 
        int h = max(height(root->left), height(root->right)) + 1;
        root->val = h;
        return h;
    }
    bool check(TreeNode * root){
        if(!root->left && !root->right)
            return true;
        else if(!root->left){
            if(root->right->val != 1)
                return false;
            else
                return true;
        }
        else if(!root->right){
            if(root->left->val != 1)
                return false;
            else
                return true;
        }
        else if(abs(root->left->val - root->right->val) > 1){
            return false;
        }else{
            return check(root->left) && check(root->right);
        }
    }
    bool isBalanced(TreeNode* root){
        if(!root)
            return true;
        height(root);
        return check(root);
    }
};
