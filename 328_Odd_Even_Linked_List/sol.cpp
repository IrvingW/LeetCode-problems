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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)    return head;
        ListNode * odd = head;
        ListNode * even = head->next;
        ListNode * even_head = even;
        while(even->next){
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            if(!even->next)
                break;
            even = even->next;
        }
        odd->next= even_head;
        return head;
    }
};
