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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int len_a=0;
        ListNode* tmp = headA;
        while (tmp != NULL) 
        {
            ++len_a;
            tmp = tmp->next;
        }
        int len_b=0;
        tmp = headB;
        while (tmp != NULL)
        {
            ++len_b;
            tmp = tmp->next;
        }
        
        while (len_a > len_b)
        {
            --len_a;
            headA = headA -> next;
        }
        
        while (len_b > len_a)
        {
            --len_b;
            headB = headB -> next; 
        }
        
        while (headA != headB)
        {
            headA = headA -> next;
            headB = headB -> next;
        }
        
        return headA;
    }
};