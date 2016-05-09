/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
private:
    void dfs(TreeLinkNode *cur)
    {
        if (cur == NULL) return;
        if (cur->left != NULL)
            cur->left->next = cur->right;
        if (cur->right != NULL)
            cur->right->next = (cur->next == NULL)?NULL:cur->next->left;
        dfs(cur->left);
        dfs(cur->right);
    }
    
public:
    void connect(TreeLinkNode *root) 
    {
        if (root == NULL) return;
        
        root->next = NULL;
        dfs(root);
    }
};