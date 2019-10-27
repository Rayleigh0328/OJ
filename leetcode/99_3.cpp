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
    
    void morris_trav(TreeNode* root, vector<TreeNode*> &result){
        TreeNode* cur = root;
        TreeNode* prev;
        TreeNode* last=NULL;
        
        while (cur != NULL){
            if (cur->left == NULL){
                //printf("%d\n", cur->val);
                if (last != NULL && last->val > cur->val){
                    result.push_back(last);
                    result.push_back(cur);
                }
                last = cur;
                cur = cur->right;
            }
            else{
                prev = cur->left;
                while (prev->right != NULL && prev->right != cur)
                    prev = prev->right;
                if (prev->right == NULL){
                    prev->right = cur;
                    cur = cur->left;
                }
                else {
                    // printf("%d\n", cur->val);
                    if (last != NULL && last->val > cur->val){
                        result.push_back(last);
                        result.push_back(cur);
                    }
                    last = cur;
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
    }
    
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> result;
        morris_trav(root,result);
        if (result.size()==2)
            swap(result[0]->val, result[1]->val);
        else 
            swap(result[0]->val, result[3]->val);
    }
};
