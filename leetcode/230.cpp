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
    map<TreeNode*, int> mp;
    
    void init_mp(TreeNode* cur)
    {
        if (cur == NULL) return;
        init_mp(cur->left);
        init_mp(cur->right);
        mp[cur] = mp[cur->left] + mp[cur->right] + 1;
    }
    
    int solve(TreeNode* cur, int k)
    {
        if (k == mp[cur->left] + 1) return cur->val;
        if (k <= mp[cur->left]) return solve(cur->left, k);
        if (k > mp[cur->left] + 1) return solve(cur->right, k-mp[cur->left]-1);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        mp.clear();
        mp[NULL] = 0;
        init_mp(root);
        return solve(root,k);
    }
};