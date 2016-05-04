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
    struct trav_state
    {
        TreeNode* node;
        int step;
        trav_state(TreeNode* p, int s):node(p),step(s){}
    };
    
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        if (root == NULL) return vector<int>();
        
        stack<trav_state> st;
        while (!st.empty()) st.pop();
        
        vector<int>ans;
        ans.clear();
        
        st.push(trav_state(root, 0));
        while (!st.empty())
        {
            trav_state state = st.top();
            st.pop();
            if (state.step == 0)
            {
                ++state.step;
                st.push(state);
                if (state.node->left != NULL)
                    st.push(trav_state(state.node->left,0));
            }
            else if (state.step == 1)
            {
                ans.push_back(state.node->val);
                ++state.step;
                st.push(state);
                if (state.node->right != NULL)
                    st.push(trav_state(state.node->right, 0));
            }
        }
        return ans;
    }
};