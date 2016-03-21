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
    typedef pair<TreeNode*, int> state;
    stack<state> st;
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        if (root == NULL) return vector<int>();
        vector<int> ans;
        ans.clear();
        
        while (!st.empty()) st.pop();
        
        st.push(state(root, 0));
        while (!st.empty())
        {
            TreeNode* cur = st.top().first;
            int stage = st.top().second;
            st.pop();
            switch (stage)
            {
                case 0:
                    st.push(state(cur, stage+1));
                    if (cur->left != NULL)
                        st.push(state(cur->left, 0));
                    break;
                case 1:
                    st.push(state(cur, stage+1));
                    if (cur->right != NULL)
                        st.push(state(cur->right, 0));
                    break;
                case 2:
                    ans.push_back(cur->val);
                    break;
            }
        }
        
        return ans;
    }
};