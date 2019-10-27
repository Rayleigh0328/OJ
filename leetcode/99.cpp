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
    
    void dfs(TreeNode* root, vector<TreeNode*> &result){
        if (root == NULL) return;
        dfs(root->left, result);
        result.push_back(root);
        dfs(root->right, result);
    }
    
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> result;
        dfs(root, result);
        vector<TreeNode*> ans;
        for (int i=1;i<result.size();++i)
            if (result[i]->val < result[i-1]->val){
                ans.push_back(result[i-1]);
                ans.push_back(result[i]);
            }
        
        if (ans.size() == 2)
            swap(ans[0]->val, ans[1]->val);
        else 
            swap(ans[0]->val, ans[3]->val);
    }
};
