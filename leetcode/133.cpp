/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    
    unordered_map<Node*, Node*> proj;
    
    Node* dfs(Node* u){
        
        Node* u_copy = new Node();
        u_copy->val = u->val;
        u_copy->neighbors={};
        proj[u] = u_copy;
        
        for (Node* v : u->neighbors){
            if (proj.find(v) != proj.end()){
                u_copy->neighbors.push_back(proj[v]);
            }
            else {
                u_copy->neighbors.push_back(dfs(v));
            }
        }
        
        return u_copy;
    }
    
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        return dfs(node);
    }
};
