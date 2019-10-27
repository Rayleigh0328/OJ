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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* cur = root;
        while (cur != NULL){
            if (cur->left == NULL){
                result.push_back(cur->val);
                cur = cur->right;
            }
            else {
                TreeNode* prev = cur->left;
                while (prev->right != NULL && prev->right != cur) prev = prev->right;
                if (prev->right == NULL){
                    prev->right = cur;
                    cur = cur->left;
                }
                else {
                    result.push_back(cur->val);
                    // restore tree structure
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};
