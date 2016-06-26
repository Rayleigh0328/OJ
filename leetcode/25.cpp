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
        vector<int> a;
        a.clear();
        ListNode *tmp;
        while (head != NULL)
        {
            a.push_back(head->val);
            head = head->next;
        }

        vector<int>::iterator it_l = a.begin(), it_r=a.begin();
        for (int i=0;i<a.size()/k;++i)
        {
            for (int j=0;j<k;++j) ++it_r;
            reverse(it_l, it_r);
            it_l = it_r;
        }
        
        
        ListNode *h = new ListNode(-1);
        ListNode *t = h;
        for (int i=0;i<a.size();++i)
        {
            t->next = new ListNode(a[i]);
            t = t->next;
        }
        
        h = h->next;
        return h;
    }
};