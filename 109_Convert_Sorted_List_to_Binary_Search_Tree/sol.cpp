/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode * build(int left, int right, vector<int> & v){
        if(left > right)
            return NULL;
        int mid = left + (right - left)/2;
        TreeNode * root = new TreeNode(v[mid]);
        root->left = build(left, mid - 1, v);
        root->right = build(mid + 1, right, v);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        return build(0, v.size() -1 , v);
    }
};
