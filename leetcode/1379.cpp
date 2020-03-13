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
    
    void dfs(TreeNode* cur, TreeNode* target, string &state, bool &find_flag){
        if (cur == target) {
            find_flag = true;
            return;
        }
        if (cur == NULL) return;
        
        state.push_back('L');
        dfs(cur->left, target, state, find_flag);
        if (find_flag) return;
        state.pop_back();
        
        state.push_back('R');
        dfs(cur->right, target, state, find_flag);
        if (find_flag) return;
        state.pop_back();
    }
    
    TreeNode* get_node(TreeNode* root, const string &ins){
        TreeNode* cur = root;
        for (int i=0;i<ins.size();++i)
            if (ins[i]=='L') cur = cur->left;
            else cur = cur->right;
        return cur;
    }
    
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        string state;
        bool flag = false;
        dfs(original, target, state, flag);
        // cout << state << endl;
        return get_node(cloned, state);
    }
};
