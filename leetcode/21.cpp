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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* s_head = new ListNode(0);
        ListNode* tail = s_head;
        while(!(l1 == NULL && l2 == NULL))
        {
            if (l1 != NULL && (l2 == NULL || l1->val < l2->val))
            {
                tail->next = l1;
                l1 = l1->next;
                tail = tail->next;
                tail->next = NULL;
            }
            else
            {
                tail->next = l2;
                l2 = l2 -> next;
                tail = tail->next;
                tail->next = NULL;
            }
        }
        ListNode* head = s_head -> next;
        delete s_head;
        return head;
    }
};