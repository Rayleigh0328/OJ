/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    
    void solve(Node* p, int d, int target_depth, vector<int>& result){
        if (d == target_depth){
            result.push_back(p->val);
            return;
        }
        
        for (auto e : p->children){
            solve(e, d+1, target_depth, result);
        }
    }
    
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == NULL) return {};
        vector<vector<int>> ans;
        for (int i=0;;++i){
            vector<int> row;
            solve(root,0,i,row);
            if (row.empty()) break;
            else ans.push_back(row);
        }
        return ans;
    }
};
