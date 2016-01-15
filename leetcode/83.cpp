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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head -> next == NULL) return head;
        for (ListNode* tmp = head; tmp->next != NULL; )
        {
            ListNode *a = tmp -> next;
            ListNode *b = a -> next;
            if (a->val == tmp->val)
            {
                tmp -> next = b;
                delete a;
            }
            else tmp = tmp->next;
        }
        return head;
    }
};