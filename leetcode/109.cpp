/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
    TreeNode* solve(ListNode* head, ListNode* tail, int len){
        if (head == tail) return NULL;
        ListNode* mid = head;
        int half = (len >> 1);
        for (int i=0;i<half;++i) mid=mid->next;
        TreeNode* result = new TreeNode(mid->val);
        result->left = solve(head, mid, half);
        result->right = solve(mid->next, tail, len-half-1);
        return result;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode* tail;
        for (tail = head; tail!=NULL; tail=tail->next) ++len;
        return solve(head, tail, len);
    }
};
