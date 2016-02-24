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
    ListNode* partition(ListNode* head, int x) {
        vector<int> before;
        vector<int> after;
        before.clear();
        after.clear();
        
        ListNode* tmp = head;
        while (tmp != NULL)
        {
            if (tmp->val < x) before.push_back(tmp->val);
            else after.push_back(tmp->val);
            tmp = tmp->next;
        }
        
        ListNode* ans = NULL;
        
        for (int i=after.size()-1;i>=0;--i)
        {
            tmp = new ListNode(after[i]);
            tmp->next = ans;
            ans = tmp;
        }
        for (int i=before.size()-1;i>=0;--i)
        {
            tmp = new ListNode(before[i]);
            tmp->next = ans;
            ans = tmp;
        }
        
        return ans;
    }
};