/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
    void solve(ListNode* p, int count, vector<int>& st){
        if (count <= 0) return; 
        st.push_back(p->val);
        solve(p->next, count-1, st);
        // printf("update %d to %d\n", p->val, st[count-1]);
        p->val = st[count-1];
    }
    
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        vector<int> st;
        int count = 1;
        ListNode* p = head;
        while (count < m){
            p = p->next;
            ++count;
        }
        solve(p, n-m+1, st);
        return head;
    }
};
