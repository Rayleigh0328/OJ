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
    
    void dfs(TreeNode* cur, int depth, vector<int>&v){
        if (cur == NULL) return;
        if (depth == v.size())
            v.push_back(cur->val);
        v[depth] = max(v[depth], cur->val);
        dfs(cur->left, depth+1, v);
        dfs(cur->right, depth+1, v);
    }
    
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> v;
        dfs(root, 0, v);
        return v;
    }
};
