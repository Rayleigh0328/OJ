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
        if (head == NULL) return head;
        ListNode* st = new ListNode(-1);
        ListNode* tail = st;
        ListNode* tmp;
        while(head != NULL)
        {
            //case 1: add to ans
            if (head->next == NULL || head->next->val != head->val)
            {
                tmp = new ListNode(head->val);
                tail->next = tmp;
                tail = tmp;
                tmp = head;
                head = head->next;
                delete tmp;
            }
            else
            {
                int target = head->val;
                while (head !=NULL && head->val == target)
                {
                    tmp = head;
                    head = head->next; 
                    delete tmp;
                }
            }
            //case 2: delete
        }
        return st->next;
    }
};