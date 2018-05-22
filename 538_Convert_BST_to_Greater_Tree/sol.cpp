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
    TreeNode* convertBST(TreeNode* root) {
        vector<TreeNode *> v;
        TreeNode * p = root;
        stack<TreeNode *> s;
        while(p || !s.empty()){
            while(p){
                s.push(p);
                p = p->left;
            }
            TreeNode * t = s.top();
            s.pop();
            v.push_back(t);
            p = t->right;
        }
        int size = v.size();
        int sum = 0;
        for(int i = size - 1; i >= 0; i--){
            int temp = v[i]->val;
            v[i]->val += sum;
            sum += temp;
        }
        return root;
    }
};
