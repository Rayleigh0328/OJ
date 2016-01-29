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
        if (head == NULL || head->next == NULL) return head;
        ListNode* cur = head;
        ListNode* tmp = head->next;
        
        while (true)
        {
            ListNode* todo = tmp -> next;
            if (todo == NULL) return head;
            tmp->next = todo->next;
            todo->next = cur->next;
            cur->next = todo;
            cur = cur->next;
            tmp = tmp->next;
            if (tmp == NULL) return head;
        }
        
    }
};