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
    int getDecimalValue(ListNode* head) {
        if (head == NULL) return 0;
        ListNode* cur = head;
        int result = 0;
        while (cur != NULL){
            result = result * 2 + cur->val;
            cur = cur -> next;
        }
        return result;
    }
};
