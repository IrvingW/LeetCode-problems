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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* prefix = new ListNode(0);
        ListNode* last_node = prefix;
        while(!(l1 == NULL && l2 == NULL && carry==0)){
            ListNode* result = new ListNode(0);
            last_node->next = result;
            if(l1 == NULL && l2 == NULL){
                result->val = carry;
                carry = 0;
                break;
            }
            if(l1 == NULL){
                int sum = carry + l2->val;
                carry = sum / 10;
                result->val = sum % 10;
                l2 = l2->next;
            }
            else if(l2 == NULL){
                int sum = carry + l1->val;
                carry = sum / 10;
                result->val = sum % 10;
                l1 = l1->next;
            }
            else{
                int sum = l1->val + l2->val + carry;
                carry = sum / 10;
                result->val = sum % 10;
                l1 = l1->next;
                l2 = l2->next;
            }
            last_node = result;
        }
        
        return prefix->next;
    }
};
