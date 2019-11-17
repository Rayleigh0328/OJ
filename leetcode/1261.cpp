/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
    
    void fill(TreeNode* u, int val){
        if (u == NULL) return;
        u->val = val;
        fill(u->left, val*2 + 1);
        fill(u->right, val*2 + 2);
    }
    
    bool find(TreeNode* u, int target){
        if (u == NULL) return false;
        if (u->val == target) return true;
        return (find(u->left, target) || find(u->right, target));
    }
    
    TreeNode* root;
    
public:
    FindElements(TreeNode* r) {
        root = r;
        fill(root, 0);
    }
    
    bool find(int target) {
        return find(root, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
