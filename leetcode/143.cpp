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
    void reorderList(ListNode* head) {
        // no need to modify when length is <= 2
        if (head == NULL || head->next == NULL || head->next->next==NULL) return;
        
        ListNode* slow=head; 
        ListNode* fast=head;
        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow point to the end of first half
        ListNode* tail = slow->next;
        ListNode* todo = slow->next->next;
        ListNode* first;
        while (todo != NULL){
            first = slow->next;
            
            slow->next = todo;
            tail->next = todo->next;
            todo->next = first;
            
            todo = tail->next;
        }

        // unlink first half, second half
        // merge two lists
        ListNode* p1 = head;
        ListNode* p2 = slow->next;
        slow->next = NULL;
        ListNode* tmp;
        while (p2 != NULL){
            tmp = p2;
            p2 = p2->next;
            
            tmp->next = p1->next;
            p1->next = tmp;
            p1 = p1->next->next;
        }
    }
};
