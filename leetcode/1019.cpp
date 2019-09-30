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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> a;
        ListNode * p = head;
        while (p != NULL) {
            a.push_back(p->val);
            p = p->next;
        }
        stack<int> s;
        vector<int> ans(a.size());
        for (int i=a.size()-1; i>=0; --i){
            while (!s.empty() && s.top() <= a[i]) s.pop();
            if(s.empty()) ans[i]=0;
            else ans[i] = s.top();
            s.push(a[i]);
        }
        return ans;
    }
};
