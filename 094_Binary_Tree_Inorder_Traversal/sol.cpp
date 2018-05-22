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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
        if(!root)   return {};
        vector<int> result;
        TreeNode * p = root;
        while(p || !s.empty())  // restart deep in on a right branch or reback to last left node
        {
            while(p){
                s.push(p);
                p = p->left;
            }
            p = s.top();
            result.push_back(p->val);
            s.pop();
            
            p = p->right;
        }
        return result;
    }
};
