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
    TreeNode* v_to_t(vector<int>& a, int left, int right)
    {
        if (left == right) return NULL;
        int mid = (left + right) / 2;
        
        TreeNode* ret = new TreeNode(a[mid]);
        ret->left = v_to_t(a, left, mid);
        ret->right = v_to_t(a, mid+1, right);
        
        return ret;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return v_to_t(nums, 0, nums.size());
    }
};