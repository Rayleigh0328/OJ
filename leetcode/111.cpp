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
    const int inf = 1<<30;
    int solve(TreeNode* p)
    {
        if (p == NULL) return 0;
        if (p->left == NULL && p->right == NULL) return 1;
        
        int sub = inf;
        
        if (p->left != NULL) sub = min(sub, solve(p->left));
        if (p->right != NULL) sub = min(sub, solve(p->right));
        
        return sub + 1;
    }
public:
    int minDepth(TreeNode* root) {
        return solve(root);
    }
};