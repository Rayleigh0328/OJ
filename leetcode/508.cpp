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
    
    unordered_map<TreeNode*, int> sum;
    
    int dfs(TreeNode* cur){
        sum[cur] = cur->val;
        if (cur->left != NULL) sum[cur] += dfs(cur->left);
        if (cur->right != NULL) sum[cur] += dfs(cur->right);
        return sum[cur];
    }
    
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (root == NULL) return {};
        dfs(root);
        unordered_map<int, int> count;
        for (auto e : sum)
            ++count[e.second];
        int max_count = 0;
        for (auto e : count)
            max_count = max(max_count, e.second);
        vector<int> result;
        for (auto e : count)
            if (e.second == max_count) result.push_back(e.first);
        return result;
    }
};
