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
    
    void dfs(TreeNode* cur, vector<int>& result){
        if (cur == NULL) return;
        dfs(cur->left, result);
        result.push_back(cur->val);
        dfs(cur->right, result);
    }
    
    vector<int> to_array(TreeNode *root){
        vector<int> result;
        dfs(root, result);
        return result;
    }
    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a = to_array(root1);
        vector<int> b = to_array(root2);
        int p1 = 0, p2 = 0;
        vector<int> result;
        while (p1 < a.size() || p2 < b.size()){
            if (p1 == a.size()) result.push_back(b[p2++]);
            else if (p2 == b.size()) result.push_back(a[p1++]);
            else if (a[p1] < b[p2]) result.push_back(a[p1++]);
            else result.push_back(b[p2++]);
        }
        return result;
    }
};
