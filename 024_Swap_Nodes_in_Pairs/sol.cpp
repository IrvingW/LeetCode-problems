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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* result;
        ListNode* odd = head;
        if(head->next){
            result = head->next;
        }else{
            return head;
        }
        ListNode* even = head->next;
        
        ListNode* next_odd;
        ListNode* next_even;
        while(odd && even){
            if(even->next && even->next->next){
                next_odd = even->next;
                next_even = even->next->next;
                odd->next = next_even;
            }else if(even->next){
                next_odd = even->next;
                next_even = NULL;
                odd->next = next_odd;
            }else{
                next_odd = NULL;
                next_even = NULL;
                odd->next = NULL;
            }
            even->next = odd;
            odd = next_odd;
            even = next_even;
        }
        
        return result; 
        
    }
};
