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
    ListNode* insertionSortList(ListNode* head) 
    {
        if (head == NULL) return head;
        ListNode *p1, *p2;
        p1 = head;
        while (p1->next != NULL)
        {
            ListNode* min_pos = p1;
            p2 = p1->next;
            while (p2!=NULL)
            {
                if (p2->val < min_pos->val) min_pos = p2;
                p2 = p2->next;
            }
            swap(p1->val, min_pos->val);
            p1 = p1->next;
        }
        return head;
    }
};