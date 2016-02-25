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
        // List should have at least two element
        if (head == NULL || head -> next == NULL) return head;
        
        // add two sentinel node
        ListNode* sent_head = new ListNode(-1);
        sent_head->next = head;
        ListNode* sent_tail = new ListNode(-1);
        ListNode* tmp = head;
        while (tmp->next != NULL) tmp = tmp->next;
        tmp -> next = sent_tail;
        
        //tmp = sent_head;
        //while (tmp != NULL)
        //{
        //    cout << tmp->val << " ";
        //    tmp = tmp->next;
        //}
        
        // perform swappings
        ListNode *p1=sent_head, *p2, *p3, *p4;
        while (p1->next != sent_tail && p1->next->next != sent_tail)
        {
            p2 = p1->next;
            p3 = p2->next;
            p4 = p3->next;
            
            p1->next = p3;
            p3->next = p2;
            p2->next = p4;
            
            p1 = p1->next->next;
        }
        
        
        // delete sentinels
        tmp = sent_head;
        while (tmp->next != sent_tail) tmp = tmp->next;
        tmp->next = NULL;
        delete sent_tail;
        head = sent_head->next;
        delete sent_head;
        
        return head;
    }
};