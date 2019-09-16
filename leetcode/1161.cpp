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
    const int inf = 2000000000;
    vector<int> sum;
    
    void dfs(TreeNode* p, int dep){
        if (p == NULL) return;
        if (dep == sum.size()) sum.push_back(p->val);
        else sum[dep] += p->val;
        dfs(p->left, dep + 1);
        dfs(p->right, dep + 1);
    }
    
public:
    int maxLevelSum(TreeNode* root) {
        if (root == NULL) return -1;
        dfs(root, 0);
        int pos = 0;
        for (int i=1; i<sum.size();++i)
            if (sum[i] > sum[pos]) pos = i;
        return pos + 1;
    }
};
