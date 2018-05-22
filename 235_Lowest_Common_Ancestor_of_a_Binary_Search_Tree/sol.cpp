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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        int pp = p->val;
        int qq = q->val;
        int cur = root->val;
        if(cur < min(pp, qq))
            return lowestCommonAncestor(root->right, p, q);
        else if(cur > max(pp, qq))
            return lowestCommonAncestor(root->left, p, q);
        else if(cur == pp)
            return p;
        else if(cur == qq)
            return q;
        else
            return root;
    }
};
