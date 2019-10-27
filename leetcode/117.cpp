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
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;
        
        unordered_map<Node*, int> depth;
        queue<Node*> que;
        que.push(root);
        depth[root] = 0;
        
        while (!que.empty()){
            Node* p = que.front();
            if (p->left != NULL){
                depth[p->left] = depth[p] + 1;
                if (depth[que.back()] == depth[p->left]) 
                    que.back()->next = p->left;
                que.push(p->left);
            }
            if (p->right != NULL){
                depth[p->right] = depth[p] + 1;
                if (depth[que.back()] == depth[p->right]) 
                    que.back()->next = p->right;
                que.push(p->right);
            }
            que.pop();
        }
        return root;
    }
};
