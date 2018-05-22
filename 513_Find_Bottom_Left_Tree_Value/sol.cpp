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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> q;
        queue<TreeNode *> last_level;
        q.push(root);
        int size = 1;
        while(!q.empty()){
            while(!last_level.empty())
                last_level.pop();
            for(int i = 0; i < size; i++){
                TreeNode * t = q.front();
                q.pop();
                last_level.push(t);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            size = q.size();
        }
        TreeNode * bf = last_level.front();
        return bf->val;
    }
};
