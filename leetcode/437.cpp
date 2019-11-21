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
    
    int f(TreeNode* u, int target){
        if (u == NULL) return 0;
        int result = (u->val == target?1:0);
        result += f(u->left, target - u->val);
        result += f(u->right, target - u->val);
        return result;
    }
    
    int g(TreeNode* u, int target){
        if (u == NULL) return 0;
        return g(u->left, target) + g(u->right, target) + f(u->left, target) + f(u->right, target);
    }
    
public:
    int pathSum(TreeNode* root, int sum) {
        return f(root, sum) + g(root, sum);
    }
};
