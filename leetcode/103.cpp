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
    struct log_type
    {
        int data;
        int depth;
        int stamp;
        
        log_type(int d, int dp, int st):
            data(d),
            depth(dp),
            stamp(st)
        {}
        
        bool operator<(const log_type& other) const
        {
            if (depth < other.depth) return true;
            if (depth > other.depth) return false;
            
            if (depth%2 == 0)
                return stamp < other.stamp;
            else
                return stamp > other.stamp;
        }
    };
    
    int stamp;
    vector<log_type> a;
    
    void traverse(TreeNode* p, int depth)
    {
        a.push_back(log_type(p->val, depth, stamp++));
        
        if (p->left != NULL) traverse(p->left, depth+1);
        if (p->right != NULL) traverse(p->right, depth+1);
    }
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        a.clear();
        stamp = 0;
        
        if (root == NULL) return vector<vector<int>>();
        traverse(root,0);
        
       
        sort(a.begin(), a.end());
         
        vector<vector<int>> result;
        result.clear();
        
        int max_dep = a[a.size()-1].depth;
        cout << max_dep << endl;
        for (int i=0;i<=max_dep;++i)
        {
            result.push_back(vector<int>());
            result[result.size()-1].clear();
        }
        
        for (int i=0;i<a.size();++i)
        {
            result[a[i].depth].push_back(a[i].data);
        }
        return result;
    }

};