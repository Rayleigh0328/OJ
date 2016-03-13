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
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* ans = NULL;
        ListNode* tail = NULL;
        
        for (ListNode* tmp = head; tmp!=NULL; tmp = tmp->next)
            if (tmp->val != val)
            {
                ListNode* q = new ListNode(tmp->val);
                if (ans == NULL)
                    ans = tail = q;
                else
                {
                    tail -> next = q;
                    tail = q;
                }
            }
        return ans;
    }
};