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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> s;
        if(!root)   return result;
        s.push(root);
        while(!s.empty()){
            TreeNode * t = s.top();
            result.push_back(t->val);
            s.pop();
            if(t->right)        // right should be first
                s.push(t->right);
            if(t->left)
                s.push(t->left);

        }
        return result;
    }
};
