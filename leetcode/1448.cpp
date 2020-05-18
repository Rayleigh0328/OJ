/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    const int inf = (1<<28);
    int result;
    
    void dfs(TreeNode* u, int cur_max){
        if (u == NULL) return;
        if (u->val >= cur_max) ++result;
        cur_max = max(u->val, cur_max);
        dfs(u->left, cur_max);
        dfs(u->right, cur_max);
    }
    
public:
    int goodNodes(TreeNode* root) {
        result = 0;
        dfs(root, -inf);
        return result;
    }
};
