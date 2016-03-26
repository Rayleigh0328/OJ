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
    vector<TreeNode*> solve(set<int>& s)
    {
        vector<TreeNode*> ans;
        ans.clear();
        
        if (s.size() == 0) return ans;
        if (s.size() == 1) 
        {
            set<int>::iterator it = s.begin();
            ans.push_back(new TreeNode(*it));
            return ans;
        }
        
        set<int> left_set;
        left_set.clear();
        set<int> right_set(s);
        
        set<int>::iterator tmp_it;
        
        for (set<int>::iterator it=s.begin(); it!=s.end(); ++it )
        {
            int root_val = *it;
            
            tmp_it = right_set.find(root_val);
            right_set.erase(tmp_it);
            
            vector<TreeNode*> left_vec = solve(left_set);
            vector<TreeNode*> right_vec = solve(right_set);
            
            if (left_vec.empty())  // left_empty
                for (int i=0;i<right_vec.size();++i)
                {
                    TreeNode* tmp = new TreeNode(root_val);
                    tmp->left = NULL;
                    tmp->right = right_vec[i];
                    ans.push_back(tmp);
                }
            else if (right_vec.empty()) // right_empty
                for (int i=0;i<left_vec.size();++i)
                {
                    TreeNode* tmp = new TreeNode(root_val);
                    tmp->right = NULL;
                    tmp->left = left_vec[i];
                    ans.push_back(tmp);
                }
            else // otherwise
                for (int i=0;i<left_vec.size();++i)
                    for (int j=0;j<right_vec.size();++j)
                    {
                        TreeNode* tmp = new TreeNode(root_val);
                        tmp->left = left_vec[i];
                        tmp->right = right_vec[j];
                        ans.push_back(tmp);
                    }
            
            left_set.insert(root_val);
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) 
    {
        vector<TreeNode*> ans;
        
        set<int> init_set;
        init_set.clear();
        for (int i=1;i<=n;++i)
            init_set.insert(i);
            
        ans = solve(init_set);
        return ans;
    }
};