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
    
    string trim_dash(string st, int from, int to){
        string ans="";
        for (int i=from; i<to-1; ++i)
            if (st[i]=='-' && isdigit(st[i+1])) {}
            else {
                ans += st[i];
            }
        ans += st[to-1];
        return ans;
    }
    
    TreeNode* solve(string st){
        // cout << "solve: " << st << endl;
        int pos = 0;
        int value = 0;
        while (pos < st.length() && isdigit(st[pos])){
            value = value * 10 + st[pos++] - '0';
        }
        TreeNode *root = new TreeNode(value);
        // no child
        if(pos == st.length()) return root; 
        
        int split_pos = -1;
        for (int i = pos+1; i < st.length()-1; ++i)
            if(isdigit(st[i-1]) && st[i]=='-' && isdigit(st[i+1])) split_pos = i;
        
        // printf("split at: %d\n", split_pos);
        
        if (split_pos == -1){
            // only left child
            root->left = solve(trim_dash(st, pos, st.length()));
        }
        else {
            // both child
            root->left = solve(trim_dash(st, pos, split_pos));
            root->right = solve(trim_dash(st, split_pos, st.length()));
        }
        return root;
    }
public:
    TreeNode* recoverFromPreorder(string st) {
        return solve(st);
    }
};

