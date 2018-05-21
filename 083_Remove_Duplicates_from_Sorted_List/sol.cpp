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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * result = head;
        if(!head)   return NULL;
        ListNode * last = head;
        head = head->next;
        while(head){
            if(head->val == last->val){
                last->next = head->next;
            }else{
                last = head;
            }
            head = last->next;
        }
        return result;
    }
};
