/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode * reverse(ListNode * node){
        ListNode * dummy = new ListNode(-1);
        while(node){
            ListNode * temp = node->next;
            node->next = dummy->next;
            dummy->next = node;
            node = temp;
        }
        return dummy->next;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head)   return true;
        int len = 0;
        ListNode * n = head;
        while(n){
            len ++;
            n = n->next;
        }
        if(len == 1)    return true;
        
        int half = (len + 1)/2;
        ListNode * tail = head;
        for(int i = 1; i < half; i++){
            tail = tail->next;
        }
        ListNode* h2 = reverse(tail);    
        while(h2 && head){
            if(h2->val != head->val)
                return false;
            h2 = h2->next;
            head = head->next;
        }
        return true;
    }
};
