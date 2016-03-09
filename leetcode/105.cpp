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
    TreeNode* build(int la, int ra, int lb, int rb, vector<int>& a, vector<int>& b)
    {
        if (la >= ra) return NULL;
        int pos;
        for (pos = lb; pos < rb; ++pos) 
            if (b[pos] == a[la]) break;
            
        int left_size = pos - lb;
        
        TreeNode* tmp = new TreeNode(a[la]);
        tmp->left = build(la+1, la+left_size+1, lb, pos, a, b);
        tmp->right = build(la+left_size+1, ra, pos+1, rb, a, b);
        return tmp;
    }
    
public:
    TreeNode* buildTree(vector<int>& a, vector<int>& b) {
        int len = a.size();
        return build(0,len, 0, len, a, b);
    }
};