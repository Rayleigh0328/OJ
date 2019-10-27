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
    
    TreeNode* solve(TreeNode* root){
        if (root->left == NULL && root->right == NULL) return root;
        if (root->left == NULL && root->right != NULL) return solve(root->right);
        if (root->left != NULL && root->right == NULL) {
            root->right = root->left;
            root->left = NULL;
            return solve(root->right);
        }
        
        TreeNode* s1 = root->left;
        TreeNode* e1 = solve(root->left);
        TreeNode* s2 = root->right;
        TreeNode* e2 = solve(root->right);
        root->left = NULL;
        root->right = s1;
        e1->right = s2;
        return e2;
    }
public:
    void flatten(TreeNode* root) {
        if (root == NULL) return ;
        solve(root);
    }
};
