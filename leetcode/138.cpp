/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        
        unordered_map<Node*, Node*> proj;
        Node* head_copy = new Node(head->val, NULL, NULL);
        proj[head] = head_copy;
        
        Node* tail_copy = head_copy;
        Node* cur = head->next;
    
        while (cur!=NULL){
            Node* new_copy = new Node(cur->val, NULL, NULL);
            proj[cur] = new_copy;
            tail_copy->next = new_copy;
            tail_copy = new_copy;
            cur = cur->next;
        }
        
        cur = head;
        Node *cur_copy = head_copy;
        while (cur != NULL){
            cur_copy->random = (cur->random==NULL?NULL:proj[cur->random]);
            cur = cur->next;
            cur_copy = cur_copy->next;
        }
        
        return head_copy;
    }
};
