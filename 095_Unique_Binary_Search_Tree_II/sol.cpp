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
    vector<TreeNode*> * dfs(int start, int end){
        vector<TreeNode*> * res = new vector<TreeNode*>;
        if(start > end){
            res->push_back(NULL);
            return res;
        }
        if(start == end){
            res->push_back(new TreeNode(start));
            return res;
        }
        for(int i = start; i <= end; i++){
            vector<TreeNode*> * left = dfs(start, i -1);
            vector<TreeNode*> * right = dfs(i + 1, end);
            for(int j = 0; j < left->size(); j++){
                for(int k = 0; k < right->size(); k++){
                    TreeNode * root = new TreeNode(i);
                    root->left = (*left)[j];
                    root->right = (*right)[k];
                    res->push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)  return {};
        else return *dfs(1, n);
    }
};
