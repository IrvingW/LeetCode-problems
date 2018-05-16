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
    void traverse(vector<string> & result, string prefix, TreeNode* cur){
        prefix += "->";
        prefix += to_string(cur->val);
        if(!cur->left && !cur->right){   // leaf
            result.push_back(prefix);
            return;
        }
        if(cur->left){
            traverse(result, prefix, cur->left);
        }
        if(cur->right){
            traverse(result, prefix, cur->right);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(!root)   return result;
        if(!root->left && !root->right){
            result.push_back(to_string(root->val));
            return result;
        }
        if(root->left)
            traverse(result, to_string(root->val), root->left);
        if(root->right)
            traverse(result, to_string(root->val), root->right);
        return result;
    }
};
