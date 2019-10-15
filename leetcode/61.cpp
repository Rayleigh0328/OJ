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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;
        int len = 1;
        ListNode* p = head;
        while (p->next != NULL){
            ++len;
            p = p-> next;
        }
        if (len == 1) return head;
        p->next = head;
        int step = len - k % len;
        p = head;
        for(int i=0;i<step;++i)
            p = p->next;
        head = p;
        for (int i=0;i<len-1;++i) p = p->next;
        p->next = NULL;
        return head;
    }
};
