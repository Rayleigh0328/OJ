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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        unordered_set<ListNode*> visited;
        visited.emplace(head);
        ListNode* p;
        for (
            p=head; 
            p->next != NULL && visited.find(p->next)==visited.end();
            visited.emplace(p->next), p=p->next
        );
        return p->next;
    }
};
