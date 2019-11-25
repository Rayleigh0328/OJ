/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    void dfs_encode(TreeNode* cur, string& result){
        if (cur == NULL) return;
        result+=to_string(cur->val) + ",";
        dfs_encode(cur->left, result);
        dfs_encode(cur->right, result);
    }
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        dfs_encode(root, result);
        if (!result.empty()) result.pop_back();
        return result;
    }

    void split(string &data, vector<int>&a){
        int pos = 0;
        int next;
        while (pos < data.size()){
            next = data.find(',', pos);
            if (next == string::npos) next = data.size();
            a.push_back(stoi(data.substr(pos, next-pos)));
            pos = next + 1;
        }
    }
    
    TreeNode* dfs_decode(const vector<int>&a, int left, int right){
        if (left == right) return NULL;
        int mid = left+1;
        while (mid<right && a[mid] <= a[left]) ++mid;
        TreeNode* result = new TreeNode(a[left]);
        result->left = dfs_decode(a, left+1, mid);
        result->right = dfs_decode(a, mid, right); 
        return result;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> a;
        split(data, a);
        for (auto x : a) printf("%d\n", x);
        return dfs_decode(a,0,a.size());
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
