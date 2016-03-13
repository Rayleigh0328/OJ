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
    void dfs(TreeNode* cur, string path, vector<string>& ans)
    {
        // leaf
        if (cur->left == NULL && cur->right == NULL)
        {
            path = path + to_string(cur->val);
            ans.push_back(path);
            return;
        }
        
        path = path + to_string(cur->val) + "->";
        if (cur->left != NULL)
            dfs(cur->left, path, ans);
        if (cur->right != NULL)
            dfs(cur->right, path, ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        ans.clear();
        if (root==NULL) return ans;
        
        string init="";
        dfs(root, init, ans);
        return ans;
    }
};