/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> count;
    int result;
    
    bool is_leaf(TreeNode *u){
        return (u->left == NULL && u->right == NULL);
    }
    
    bool feasible(vector<int> &count){
        
        // cout << "check: ";
        // for (int i=0;i<10;++i)
        //     cout << count[i];
        // cout << endl;
        
        int odd_count = 0;
        for (int i=1;i<10;++i)
            if (count[i] & 1) ++odd_count;
        return (odd_count <= 1);
    }
    
    void dfs(TreeNode* u){
        if (u == NULL) return;
        if (is_leaf(u) && feasible(count)) ++result;
        
        if (u->left != NULL){
            ++count[u->left->val];
            dfs(u->left);
            --count[u->left->val];
        }
        
        if (u->right != NULL){
            ++count[u->right->val];
            dfs(u->right);
            --count[u->right->val];
        }
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        if (root == NULL) return 0;
        
        count = vector<int>(10,0);
        result = 0;
        
        ++count[root->val];
        dfs(root);
        
        return result;
    }
};
