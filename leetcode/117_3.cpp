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
        if (root == NULL) return root;
        Node* special = new Node(-1, NULL, NULL, NULL);
        root->next = special;
        Node* p1 = root;
        Node* p2 = special;
        
        while (p1 != NULL){
            if (p1->left != NULL) {p2->next = p1->left; p2 = p2->next;}
            if (p1->right != NULL) {p2->next = p1->right; p2 = p2->next;}
            if (p1->next == special){
                p1->next = NULL;
                p1 = special->next;
                special->next = NULL;
                p2->next = special;
                p2 = special;
                
            }
            else{
                p1 = p1->next;
            }
        }
        
        return root;
    }
};
