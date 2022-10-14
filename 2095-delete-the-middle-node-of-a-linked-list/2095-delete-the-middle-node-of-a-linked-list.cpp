/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(slow==fast)
            return NULL;
        if(slow->next==NULL){
         //   slow=NULL;
            head->next=NULL;
            return head;
        }
            
        ListNode* nxt = slow->next;
        slow->val = nxt->val;
        slow->next = nxt->next;
        delete(nxt);
        return head;
    }
};