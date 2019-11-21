/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
    
    Node* solve(Node* root){
        Node* p = root;
        while (p->next != NULL || p->child != NULL){
            if (p->child == NULL){
                p = p->next;
            }
            else {
                Node* v = solve(p->child);
                Node* u = p->child;
                Node* w = p->next;
                
                p->child = NULL;
                p->next = u;
                u->prev = p;
                v->next = w;
                if (w != NULL) w->prev = v;
            }
        }
        return p;
    }
    
public:
    Node* flatten(Node* head) {
        if (head == NULL) return head;
        solve(head);
        return head;
    }
};
