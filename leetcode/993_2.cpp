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
    void dfs(TreeNode* node, int depth, unordered_map<int,int> &dist){
        if (node == NULL) return ;
        dist[node->val] = depth;
        dfs(node->left, depth+1, dist);
        dfs(node->right, depth+1, dist);
    }
    
    bool dfs_same_parent(TreeNode* node, int x, int y){
        if (node == NULL) return false;
        if (node->left != NULL && node->right != NULL && ((node->left->val == x && node->right->val == y) || (node->left->val == y && node->right->val == x)) ) return true;
        
        return (dfs_same_parent(node->left, x, y) || dfs_same_parent(node->right, x, y));
    }
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int,int> dist;
        dfs(root, 0, dist);
        if (dist.find(x) != dist.end() && 
            dist.find(y) != dist.end() && 
            dist[x] == dist[y])
            return !dfs_same_parent(root, x,y);
        return false;
    }
};
