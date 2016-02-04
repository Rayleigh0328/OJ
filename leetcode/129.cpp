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
    int sumNumbers(TreeNode* root) {
        sum = 0;
        dfs(root,0);
        return sum;
    }
private:
    int sum;
    void dfs(TreeNode* p, int cur)
    {
        if (p == NULL)
        {
            //sum += cur;
            return;
        }
        cur = cur * 10 + p->val;
        if (p->left == NULL && p->right == NULL)
        {
            sum += cur;
            return;
        }
        
        dfs(p->left, cur);
        dfs(p->right, cur);
    }
};