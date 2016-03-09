/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    vector<TreeNode*> path;
    TreeNode* cur;
public:
    BSTIterator(TreeNode *root) {
        path.clear();
        path.push_back(root);
        cur = root;
        if (cur == NULL) return;
        
        while (cur->left != NULL)
        {
            path.push_back(cur->left);
            cur = cur->left;
        }
        cout << cur->val << endl;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        if (cur == NULL) return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        int ans = cur->val;
        
        if (cur->right != NULL)
        {
            cout << "case 1" << endl;
            
            cur = cur->right;
            path.push_back(cur);
            while (cur->left != NULL)
            {
                path.push_back(cur->left);
                cur = cur->left;
            }
            return ans;
        }
        
        cout << "case 2" << endl;
        if (path.size() == 1)
        {
            cur = NULL;
            return ans;
        }
        TreeNode *prev = path[path.size() - 2];
        while (cur == prev->right)
        {
            cur = prev;
            path.pop_back();
            if (path.size() == 1)
            {
                cur = NULL;
                return ans;
            }
            prev = path[path.size()-2];
        }
        cur = prev;
        path.pop_back();
        return ans;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */