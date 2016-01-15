/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 // scan twice
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int tot = 0;
        for (ListNode* tmp = head; tmp != NULL; tmp = tmp->next, ++tot);
        
        if (n == tot)
        {
            ListNode* tmp = head;
            head = head -> next;
            delete tmp;
            return head;
        }
        
        int target = tot - n;
        int cnt=0;
        ListNode* tmp;
        for (tmp = head; cnt < target-1; ++cnt, tmp = tmp->next);
        ListNode* to_del = tmp->next;
        tmp -> next = to_del -> next;
        delete to_del;
        return head;
    }
};
*/

//scan once
class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* left = head;
        ListNode* right = head;
        for (int i=0;i<n;++i) right = right -> next;
        if (right == NULL) return head->next;
        right = right->next;
        
        while (right != NULL)
        {
            left = left->next;
            right = right->next;
        }
        ListNode* tmp = left->next;
        left->next = tmp->next;
        return head;
    }
};