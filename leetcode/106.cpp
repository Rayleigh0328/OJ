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
private:
    TreeNode* solve(int la, int ra, int lb, int rb, vector<int>& a, vector<int>& b)
    {
        if (la > ra) return NULL;
        int x;
        for (x = la; x<=ra; ++x)
            if (a[x] == b[rb]) break;
        int len = x-la;
        TreeNode* tmp = new TreeNode(a[x]);
        tmp->left = solve(la, x-1, lb, lb+len-1, a, b);
        tmp->right = solve(x+1, ra, lb+len, rb-1, a, b);
    }
public:
    TreeNode* buildTree(vector<int>& a, vector<int>& b) {
        return solve(0,a.size()-1,0,b.size()-1,a,b);
    }
};