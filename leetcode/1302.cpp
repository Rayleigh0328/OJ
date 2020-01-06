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
    
    void dfs(TreeNode* root, int depth, vector<int>&v){
        if (root == NULL) return;
        if (v.size() == depth) v.push_back(0);
        v[depth] += root->val;
        dfs(root->left, depth+1, v);
        dfs(root->right, depth+1, v);
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        vector<int> v;
        dfs(root, 0, v);
        return v.back();
    }
};
