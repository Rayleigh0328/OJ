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
public:
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        
        mp.clear();
        mp[NULL] = 0;
        dfs_mp(root);
        
        int ans = -inf;
        get_ans(ans, root);
        
        return ans;
    }
private:
    map<TreeNode*, int> mp;
    const int inf = 1<<30;
    
    void dfs_mp(TreeNode* cur)
    {
        if (cur == NULL) return ;
        dfs_mp(cur->left);
        dfs_mp(cur->right);
        mp[cur] = max(0, max(mp[cur->left], mp[cur->right])) + cur->val;
        cout << mp[cur] << endl;
    }
    
    void get_ans(int& ans, TreeNode* cur)
    {
        if (cur == NULL) return ;
        int tmp = cur->val;
        if (mp[cur->left] > 0) tmp += mp[cur->left];
        if (mp[cur->right] > 0) tmp += mp[cur->right];
        ans = max(ans,tmp);
        get_ans(ans, cur->left);
        get_ans(ans, cur->right);
    }
};