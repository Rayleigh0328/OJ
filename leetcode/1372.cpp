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
    unordered_map<TreeNode*, int> f,g;
    
    void dfs(TreeNode* cur){
        TreeNode* lc = cur->left;
        if (lc != NULL){
            f[lc] = g[cur] + 1;
            g[lc] = 1;
            dfs(lc);
        }
        TreeNode* rc = cur->right;
        if (rc != NULL){
            f[rc] = 1;
            g[rc] = f[cur] + 1;
            dfs(rc);
        }
    }
    
public:
    int longestZigZag(TreeNode* root) {
        int result = 0;
        f[root] = g[root] = 1;
        dfs(root);
        for (auto entry : f){
            result = max(result, entry.second);
        }
        for (auto entry : g){
            result = max(result, entry.second);
        }
        return result - 1;
    }
};
