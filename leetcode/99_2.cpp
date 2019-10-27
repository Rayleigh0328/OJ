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
    
    void dfs(TreeNode* root, vector<TreeNode*>& result){
        if (root == NULL) return;
        dfs(root->left, result);
        if (root->left != NULL){
            TreeNode* prev = root->left;
            while (prev->right != NULL) prev = prev->right;
            if (prev->val > root->val){
                result.push_back(prev);
                result.push_back(root);
            }
        }
        if (root->right != NULL){
            TreeNode* next = root->right;
            while (next->left != NULL) next = next->left;
            if (root->val > next->val){
                result.push_back(root);
                result.push_back(next);
            }
        }
        dfs(root->right, result);
    }
    
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> result;
        dfs(root, result);
        if (result.size() == 2)
            swap(result[0]->val, result[1]->val);
        else 
            swap(result[0]->val, result[3]->val);
    }
};
