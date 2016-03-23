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
    map<TreeNode*, int> f; // with root
    map<TreeNode*, int> g; // without root
    
    void solve(TreeNode* cur)
    {
        if (cur->left != NULL) solve(cur->left);
        if (cur->right != NULL) solve(cur->right);
        f[cur] = cur->val + g[cur->left] + g[cur->right];
        g[cur] = max(f[cur->left], g[cur->left]) + max(f[cur->right], g[cur->right]);
    }
    
public:
    int rob(TreeNode* root) 
    {
        if (root == NULL) return 0;
        f.clear();
        g.clear();
        f.emplace((TreeNode*)NULL, 0);
        g.emplace((TreeNode*)NULL, 0);
        solve(root);
        return max(f[root], g[root]);
    }
};