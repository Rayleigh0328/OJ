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
    
    void solve(TreeNode *p, vector<int> &v){
        if (p == NULL) return;
        if (p->left == NULL && p->right == NULL) v.push_back(p->val);
        solve(p->left, v);
        solve(p->right, v);
    }
    
    bool check_equal(const vector<int>&v1, const vector<int>&v2){
        if (v1.size() != v2.size()) return false;
        for (int i=0;i<v1.size();++i)
            if (v1[i] != v2[i]) return false;
        return true;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        solve(root1, v1);
        vector<int> v2;
        solve(root2, v2);
        return check_equal(v1,v2);
    }
};
