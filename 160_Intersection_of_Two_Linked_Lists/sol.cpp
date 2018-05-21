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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * a = headA;
        ListNode * b = headB;
        if(a == NULL || b == NULL)  return NULL;
        while(a->next){
            a = a->next;
        }
        while(b->next){
            b = b->next;
        }
        if(a != b)  return NULL;
        
        ListNode * A = headA;
        ListNode * B = headB;
        while(headA != headB){
            headA = (headA->next == NULL) ? B : headA->next;
            headB = (headB->next == NULL) ? A : headB->next;
        }
        return headA;
    }
};
