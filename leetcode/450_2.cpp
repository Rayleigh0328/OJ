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
    
    TreeNode* get_min(TreeNode* root){
        TreeNode* cur = root;
        while (cur->left != NULL) cur = cur->left;
        return cur;
    }
    
    TreeNode* delete_node(TreeNode* root, int key){
        if (root == NULL) return NULL;
        if (root->val == key){
            if (root->left == NULL && root->right == NULL) return NULL;
            if (root->left == NULL) return root->right;
            if (root->right == NULL) return root->left;
            
            TreeNode* u = get_min(root->right);
            swap(root->val, u->val);
            root->right = delete_node(root->right, key);
            return root;
        }
        else if (root->val > key){
            root->left = delete_node(root->left, key);
            return root;
        }
        else {
            root->right = delete_node(root->right, key);
            return root;
        }
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return delete_node(root, key);
    }
};
