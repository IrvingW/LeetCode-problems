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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        while(n > 1){
            int k = (n + 1)/2;
            for(int i = 0; i < n/2; i++){
                lists[i] = merge2Lists(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
        
    } 
    
    ListNode* merge2Lists(ListNode* list1, ListNode* list2){
        ListNode *result = new ListNode(-1);
        ListNode *curNode = result;
        while(list1 != NULL || list2 != NULL){
            if(list1 == NULL){
                curNode->next = list2;
                break;
            }
            if(list2 == NULL){
                curNode->next = list1;
                break;
            }
            else{
                if(list1->val < list2->val){
                    curNode->next = list1;
                    list1 = list1->next;
                }else{
                    curNode->next = list2;
                    list2 = list2->next;
                }
                
                curNode = curNode->next;
            }
        }
        return result->next;
    }
};
