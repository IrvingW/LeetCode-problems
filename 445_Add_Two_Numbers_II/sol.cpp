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
        if(!l1 || l1->val == 0)
            return l2;
        if(!l2 || l2->val == 0)
            return l1;
        
        stack<int> s1;
        stack<int> s2;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        int result = 0;
        ListNode * dummy = new ListNode(-1);
        while(!s1.empty() && !s2.empty()){
            int sum = s1.top() + s2.top() + carry;
            s1.pop();
            s2.pop();
            ListNode * n = new ListNode(sum % 10);
            n->next= dummy->next;
            dummy->next = n;
            carry = sum / 10;
        }
        if(!s1.empty()){
            while(!s1.empty()){
                int sum = carry + s1.top();
                s1.pop();
                ListNode * n = new ListNode(sum % 10);
                n->next= dummy->next;
                dummy->next = n;
                carry = sum / 10;
            }
        }
        if(!s2.empty()){
            while(!s2.empty()){
                int sum = carry + s2.top();
                s2.pop();
                ListNode * n = new ListNode(sum % 10);
                n->next= dummy->next;
                dummy->next = n;
                carry = sum / 10;
            }            
        }
        if(carry != 0){
            ListNode * n = new ListNode(carry);
            n->next= dummy->next;
            dummy->next = n;
        }
        return dummy->next;
    }
};
