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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        int a = p->val;
        int b = q->val;
        if (a > b) swap(a,b);
        
        TreeNode* cur = root;
        while (true)
        {
            if (b<cur->val) cur=cur->left;
            else 
                if (a>cur->val) cur=cur->right;
                else return cur;
        }
    }
};