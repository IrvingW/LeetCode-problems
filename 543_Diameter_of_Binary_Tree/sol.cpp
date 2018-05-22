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
    unordered_map<TreeNode *, int> m;
public:
    int height(TreeNode * node){
        if(!node)
            return 0;
        int h = max(height(node->left), height(node->right)) + 1;
        m[node] = h;
        return h;        
        
    }
    int getHeight(TreeNode * node){
        if(!node)   return 0;
        return m[node];
    }
    int cal(TreeNode * root){
        if(!root)
            return 0;
        int result = getHeight(root->left) + getHeight(root->right);
        result = max(result, max(cal(root->left), cal(root->right)));
        return result;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return cal(root);
    }
};
