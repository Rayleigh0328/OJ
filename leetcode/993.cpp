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
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> que;
        unordered_map<int, int> dist;
        que.emplace(root);
        dist[root->val] = 0;
        while (!que.empty()){
            TreeNode* p = que.front();
            que.pop();
            if (p->left != NULL) {
                que.push(p->left);
                dist[p->left->val] = 1 + dist[p->val];
            }
            if (p->right != NULL){
                que.push(p->right);
                dist[p->right->val] = 1 + dist[p->val];
            }
            if (p->left != NULL && p->right != NULL && ((p->left->val == x && p->right->val == y) || (p->left->val == y && p->right->val == x)))
                return false;
            if (dist.find(x) != dist.end() && dist.find(y) != dist.end())
                return (dist[x] == dist[y]);
        }
        return false;
    }
};
