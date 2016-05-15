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
    vector<int> ans;
    
    void dfs(TreeNode* cur, int dep)
    {
        if (dep >= ans.size())
            ans.push_back(cur->val);
        else
            ans[dep] = cur->val;
        if (cur->left != NULL) dfs(cur->left, dep+1);
        if (cur->right != NULL) dfs(cur->right, dep+1);
    }
    
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        ans.clear();
        if (root != NULL) dfs(root, 0);
        return ans;
    }
};