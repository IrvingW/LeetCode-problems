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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n == 0)  return NULL;
        ListNode * tail = head;
        // be careful about delete the first node
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * pre = dummy;
        for(int i = 0; i < n; i++){
            tail = tail->next;
        }
        while(tail){
            tail = tail->next;
            pre = head;
            head = head->next;
        }
        pre->next = head->next;
        return dummy->next;
    }
};
