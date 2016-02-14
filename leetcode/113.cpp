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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        path.clear();
        ans.clear();
        if (root != NULL) 
            dfs(root, sum);
        return ans;
    }
    
private:
    vector<TreeNode*> path;
    vector<vector<int>> ans;
    
    void dfs(TreeNode* p, int sum)
    {
        sum -= p->val;
        path.push_back(p);
        if (sum == 0 && p->left == NULL && p->right == NULL)
        {
            ans.push_back(vector<int>());
            for (int i=0;i<path.size();++i)
                ans[ans.size()-1].push_back(path[i]->val);
        }
        
        if (p->left != NULL) dfs(p->left, sum);
        if (p->right != NULL) dfs(p->right, sum);
        path.pop_back();
    }
};