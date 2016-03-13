/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private: 
    ListNode* cur;
    ListNode* first;
    
    bool solve(ListNode* p)
    {
        bool ans = true;
        if (p->next != NULL) 
            ans = solve(p->next);
            
        if (cur == NULL) cur = first;
        else cur = cur->next;
        
        ans = ans && (p->val == cur->val);
        return ans;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        cur = NULL;
        first = head;
        return solve(head);
    }
};