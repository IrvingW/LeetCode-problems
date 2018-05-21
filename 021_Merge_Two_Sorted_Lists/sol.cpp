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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode * last = dummy;
        while(l1 && l2){           
            if(l2->val >= l1->val){
                ListNode * temp_l1 = l1->next;
                last->next = l1;
                last = l1;
                l1 = temp_l1;

            }else{
                ListNode * temp_l2 = l2->next;
                last->next = l2;
                last = l2;
                l2 = temp_l2;
            }
        }
        if(l1)
            last->next = l1;
        if(l2)
            last->next = l2;
        return dummy->next;
    }
};
