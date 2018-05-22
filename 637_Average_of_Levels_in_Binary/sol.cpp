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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if(!root)   return result;
        queue<TreeNode *> q;
        q.push(root);
        int size = 1;
        while(!q.empty()){
            double sum = 0;
            for(int i = 0; i < size; i++){
                TreeNode * t = q.front();
                sum += t->val;
                q.pop();
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            result.push_back(sum/size);
            size = q.size();
            
        }
        return result;
    }
};
