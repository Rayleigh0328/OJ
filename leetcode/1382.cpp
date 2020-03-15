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
    
    void dfs(TreeNode* cur, vector<int>& a){
        if (cur == NULL) return;
        dfs(cur->left, a);
        a.push_back(cur->val);
        dfs(cur->right, a);
    }
    
    TreeNode* construct_bst(const vector<int> &a, int left, int right){
        if (left >= right) return NULL;
        if (right == left + 1)
            return new TreeNode(a[left]);
        int mid = (left + right) / 2;
        TreeNode* result = new TreeNode(a[mid]);
        result->left = construct_bst(a, left, mid);
        result->right = construct_bst(a, mid+1, right);
        return result;
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        if (root == NULL) return NULL;
        vector<int> a;
        dfs(root, a);
        return construct_bst(a,0,a.size());
    }
};
