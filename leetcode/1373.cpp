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
    const int inf = (1<<29);
    
    unordered_map<TreeNode*, int> sum;
    unordered_map<TreeNode*, int> max_val;
    unordered_map<TreeNode*, int> min_val;
    int ans = -inf;
    
    int dfs_sum(TreeNode* cur){
        if (cur == NULL) return 0;
        return (sum[cur] = dfs_sum(cur->left) + dfs_sum(cur->right) + cur->val);
    }
    
    int dfs_max(TreeNode* cur){
        if (cur == NULL) return -inf;
        int result = cur->val;
        result = max(result, dfs_max(cur->left));
        result = max(result, dfs_max(cur->right));
        return (max_val[cur] = result);
    }
    
    int dfs_min(TreeNode* cur){
        if (cur == NULL) return inf;
        int result = cur->val;
        result = min(result, dfs_min(cur->left));
        result = min(result, dfs_min(cur->right));
        return (min_val[cur] = result);
    }
    
    bool dfs_is_bst(TreeNode* cur){
        if (cur == NULL) return true;
        bool lc = dfs_is_bst(cur->left);
        bool rc = dfs_is_bst(cur->right);
        if (!lc || !rc) return false;
        
        if (cur->left != NULL && max_val[cur->left] >= cur->val) return false;
        if (cur->right != NULL && min_val[cur->right] <= cur->val) return false;
        // cout << cur->val << endl;
        ans = max(ans, sum[cur]);
        return true;
    }
    
public:
    int maxSumBST(TreeNode* root) {
        dfs_sum(root);
        dfs_max(root);
        dfs_min(root);
        // for (auto e : sum){
        //     printf("value: %d, sum: %d, max: %d, min: %d\n", (e.first)->val, sum[e.first], max_val[e.first], min_val[e.first]);
        // }
        dfs_is_bst(root);
        return max(0,ans);
    }
};
