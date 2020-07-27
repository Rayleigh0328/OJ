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
    
    typedef vector<int> ReturnType;
    
    int result;
    int dist;
    
    bool is_leaf(TreeNode* u){
        return (u != NULL && u->left == NULL && u->right == NULL);
    }
    
    ReturnType dfs(TreeNode* u){
        if (u == NULL) return {};
        ReturnType rt_left = dfs(u->left);
        ReturnType rt_right = dfs(u->right);
        
        // printf("dfs %d\n", u->val);
        // printf("\tleft:");for (auto x : rt_left) printf("%d ",x); printf("\n");
        // printf("\tright:");for (auto x : rt_right) printf("%d ",x); printf("\n");
        
        ReturnType rt(dist,0);
        if (is_leaf(u)){
            rt[0] = 1;
            return rt;
        }
        
        for (int i=0;i<rt_left.size();++i) if (i+1 < dist) rt[i+1] += rt_left[i];
        for (int i=0;i<rt_right.size();++i) if (i+1 < dist) rt[i+1] += rt_right[i];
        
        for (int i=0;i<rt_left.size();++i)
            for (int j=0;j<rt_right.size();++j){
                if (i+j+2 <= dist) result += rt_left[i] * rt_right[j];
            }
        return rt;
    }
    
public:
    int countPairs(TreeNode* root, int distance) {
        result = 0;
        dist = distance;
        dfs(root);
        return result;
    }
};
