/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
    
    void solve(Node* root, int depth, vector<Node*> &right_most){
        if (root == NULL) return;
        if (right_most.size() == depth)
            right_most.push_back(root);
        else {
            right_most[depth]->next = root;
            right_most[depth] = root;
        }
        solve(root->left, depth+1, right_most);
        solve(root->right, depth+1, right_most);
    }
    
public:
    Node* connect(Node* root) {
        vector<Node*> right_most;
        solve(root, 0, right_most);
        return root;
    }
};
