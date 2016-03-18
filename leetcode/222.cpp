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
    int depth;
    
    void solve(TreeNode* p, int dep, int &cnt)
    {
        if (p == NULL) return ;
        
        //cout << "solve: "  << p->val << endl;
        
        TreeNode *l, *r;
        l = r = p->left;
        int fur = 0;
        while (l != NULL)
        {
            if ((l == NULL) ^ (r==NULL)!=0) 
            {
                fur = -1;
                break;
            }
            l = l->left;
            r = r->right;
            ++fur;
        }
        
        if (fur != -1 && dep + fur == depth)
        {
            cnt += (1<<(max(0,depth - dep-1)));
            solve(p->right,dep+1,cnt);
        }
        else
            solve(p->left,dep+1,cnt);
    }
    
public:
    int countNodes(TreeNode* root) 
    {
        if (root == NULL) return 0;
        
        // calculate depth
        depth = 0;
        TreeNode* tmp = root;
        while (tmp != NULL)
        {
            ++depth;
            tmp = tmp->left;
        }
        //cout << "depth: " << depth << endl;
        int cnt;
        solve(root, 1, cnt);
        //cout << "cnt: "  << cnt << endl;
        return cnt + (1<<(depth-1)) - 1;
    }
};