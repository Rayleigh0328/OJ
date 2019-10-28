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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;
        ListNode* slow=head->next;
        ListNode* fast=head->next->next;
        while (slow!=NULL && fast !=NULL && fast != slow){
            slow = slow -> next;
            if (fast->next == NULL) return NULL;
            fast = fast -> next -> next;
        }
        
        if (slow == NULL || fast == NULL) return NULL;
        ListNode* p=head;
        while (p!=slow){
            p = p->next;
            slow = slow->next;
        }
        return p;
    }
};
