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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> s;
        if(!root)   return result;
        s.push(root);
        TreeNode * last_visited = root; // important
        while(!s.empty()){
            TreeNode * t = s.top();
            if((!t->left && !t->right) || t->left == last_visited || t->right == last_visited){
                result.push_back(t->val);
                s.pop();
                last_visited = t;
                continue;
            } 
            if(t->right)
                s.push(t->right);
            if(t->left)
                s.push(t->left);
        }
        return result;
    }
};
