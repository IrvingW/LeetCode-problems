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
    int getMinimumDifference(TreeNode* root) {
        int last = -1;
        TreeNode * p = root;
        stack<TreeNode *> s;
        int result = INT_MAX;
        while(p || !s.empty()){
            while(p){
                s.push(p);
                p = p->left;
            }
            TreeNode * t = s.top();
            s.pop();
            if(last >= 0)
                result = min(result, abs(t->val - last));
            last = t->val;
            p = t->right;
        }
        return result;
    }
};
