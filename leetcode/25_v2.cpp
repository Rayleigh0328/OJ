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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode *left = head;
        ListNode *right = head;
        ListNode *tmp;
        
        // calculate length of list
        int cnt = 0;
        for (tmp = head; tmp != NULL; tmp = tmp->next) ++cnt;
        
        // add sentinel to the front
        ListNode* sent = new ListNode(-1);
        sent->next = head;
        ListNode* prev = sent;

        for (int i=0;i<cnt/k;++i)
        {
            for (int j=0;j<k-1;++j) right = right->next;
    
            while (left != right)
            {
                prev->next = right;
                for (tmp = left; tmp->next != right;) tmp = tmp->next;
                tmp->next = right->next;
                prev = right; 
                right->next = left;
                right = tmp;
            }
            prev = left;
            left = right = left->next;
        }
    
        return sent->next;
    }
};