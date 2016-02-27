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
private: 
    const long long inf = (long long)1 << 50;
    
    bool check(TreeNode* root, long long lb, long long ub)
    {
        if (root == NULL) return true;
        long long value = (long long)root->val;
        if (value <= lb || ub <= value) return false;
        return check(root->left, lb, value) && check(root->right, value, ub);
    }
public:
    bool isValidBST(TreeNode* root) 
    {
        return check(root, -inf, inf);
    }
};