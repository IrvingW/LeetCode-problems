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
    ListNode* reverseList(ListNode* head) {
        if(!head)   return NULL;
        ListNode * dummy = new ListNode(-1);
        while(head){
            ListNode * new_head= head->next;
            head->next = dummy->next;
            dummy->next = head;
            head = new_head;
        }
        return dummy->next;
    }
};
