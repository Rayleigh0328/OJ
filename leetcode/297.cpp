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
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()){
            TreeNode* u = que.front();
            que.pop();
            if (u == NULL) {
                ans+="null,";
                continue;
            }
            else {
                ans+=to_string(u->val) + ",";
            }
            que.push(u->left);
            que.push(u->right);
        }
        ans.pop_back();
        return "["+ans+"]";
    }

    vector<string> split(const string& st, char ch){
        vector<string> ans;
        int pos = 0, next_pos = st.find(ch, pos);
        while ((next_pos) != string::npos){
            ans.push_back(st.substr(pos, next_pos-pos));
            pos = next_pos + 1;
            next_pos = st.find(ch, pos);
        }
        ans.push_back(st.substr(pos));
        return ans;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> a = split(data.substr(1,data.length()-2), ',');
    
        vector<TreeNode*> que(a.size());
        for (int i=0;i<a.size();++i){
            if (a[i] == "null") 
                que[i] = NULL;
            else 
                que[i] = new TreeNode(stoi(a[i]));
        }        
        int p1 = 0, p2 = 1;
        while (p1 < p2){
            if (que[p1] == NULL) ++p1;
            else {
                que[p1]->left = que[p2++];
                que[p1++]->right = que[p2++];
            }
        }
        return que[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
