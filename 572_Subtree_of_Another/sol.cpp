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
    bool check (TreeNode * sub, TreeNode * t){
        if(!sub && ! t)
            return true;
        else if(!sub || !t)
            return false;
        
        if(sub->val != t->val)
            return false;
        
        return (check(sub->left, t->left) && check(sub->right, t->right));
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t)
            return true;
        else if(!s)
            return false;
        else if(!t)
            return false;
        
        if(s->val == t->val)
            if(check(s, t))
                return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
