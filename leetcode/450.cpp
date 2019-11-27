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
    
    TreeNode* root;
    
    TreeNode* find(TreeNode* u, int k){
        if (u == NULL) return NULL;
        if (u->val == k) return u;
        if (u->val < k) return find(u->right, k);
        else return find(u->left, k);
    }
    
    TreeNode* get_parent(TreeNode* root, TreeNode* u){
        if (u == root) return NULL;
        TreeNode* cur = root;
        while(true){
            if (cur->left == u || cur->right == u) return cur;
            if (u->val < cur->val) cur = cur->left;
            else cur = cur->right;
        }
        return NULL;
    }
    
    void unlink(TreeNode* p, TreeNode* u){
        if (p == NULL) {
            root = NULL;
            return;
        }
        if (p->left == u) p->left = NULL;
        else p->right = NULL;
    }
    
    void replace(TreeNode* p, TreeNode* u, TreeNode* c){
        if (p == NULL) root = c;
        else {
            if (u == p->left)
                p->left = c;
            else 
                p->right = c;
        }
    }
    
    TreeNode* get_min(TreeNode* u){
        TreeNode* result = u;
        while (result -> left != NULL) result = result->left;
        return result;
    }
    
    void remove(TreeNode* u){
        TreeNode* p = get_parent(root, u);
        if (u->left == NULL && u->right == NULL){
            unlink(p, u);
            return;
        }
        if (u->left == NULL) {
            replace(p, u, u->right);
            return;
        }
        if (u->right == NULL){
            replace(p, u, u->left);
            return;
        }
        
        TreeNode* v = get_min(u->right);
        u->val = v->val;
        remove(v);
    }
    
public:
    TreeNode* deleteNode(TreeNode* r, int key) {
        root = r;
        TreeNode* todo = find(root, key);
        if (todo == NULL) return root;
        remove(todo);
        return root;
    }
};
