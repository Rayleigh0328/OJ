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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* result_head = new ListNode(0);
        ListNode* result_tail = result_head;
        
        int carry = 0;
        while (p1 != NULL || p2 != NULL || carry != 0)
        {
            int tmp = carry;
            if (p1 != NULL) tmp += p1->val;
            if (p2 != NULL) tmp += p2->val ;
            
            carry = tmp / 10;
            tmp = tmp % 10;
            
            ListNode* tmp_node = new ListNode(tmp);
            result_tail->next = tmp_node;
            result_tail = tmp_node;
            
            if (p1 != NULL) p1 = p1->next;
            if (p2 != NULL) p2 = p2->next;
        }
        ListNode* d = result_head;
        result_head = result_head->next;
        delete d;
        return result_head;
    }
};