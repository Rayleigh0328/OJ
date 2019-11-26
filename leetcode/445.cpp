/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
    vector<int> get_vector(ListNode* head){
        vector<int> result;
        ListNode* cur = head;
        while (cur != NULL){
            result.push_back(cur->val);
            cur = cur->next;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    ListNode* to_list(vector<int> &a){
        reverse(a.begin(), a.end());
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
        for (int x : a){
            tail->next = new ListNode(x);
            tail = tail->next;
        }
        return head->next;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> a = get_vector(l1);
        vector<int> b = get_vector(l2);
        vector<int> result;
        int pos = 0, carry = 0, x, y;
        while (pos < a.size() || pos < b.size() || carry > 0){
            x = (pos<a.size()?a[pos]:0);
            y = (pos<b.size()?b[pos]:0);
            result.push_back((x + y + carry) % 10);
            carry = (x + y + carry) / 10;
            ++pos;
        }
        return to_list(result);
    }
};
