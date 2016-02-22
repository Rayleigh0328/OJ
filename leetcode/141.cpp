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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        
        set<ListNode*> s;
        s.clear();
        ListNode* p = head;
        while (p!=NULL)
        {
            if (s.find(p)==s.end()) s.insert(p);
            else
                return true;
            p = p->next;
        }
        return false;
    }
};