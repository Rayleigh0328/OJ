#define NDEBUG
#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

template <typename T>
class RbTree{

public:
    enum Color{
        RED, 
        BLACK
    };

    struct Node{
        T data;
        Color color=RED;
        int size = 1;
        Node *left = NULL;
        Node *right = NULL;
        Node *parent = NULL;
        
        Node(T d):data(d){}
    };

    /*
     * member and constructor
     */
    Node *root;
    RbTree():root(NULL){}

    /*
     * helper functions: get sibling, left-rotate, right-rotate
     * note the rotate here does not change color of the node
     */
    Node* get_sibling(Node* n){
        assert(n != NULL && n->parent != NULL);
        Node* p = n->parent;
        if (n == p->left) return p->right;
        else return p->left;
    }

    Color get_color(Node* n){
        if (n == NULL) return BLACK;
        return n->color;
    }

    void left_rotate(Node* n){
#ifndef NDEBUG
        std::cout << "left rotate" << std::endl;
#endif
        Node* p = n->parent;
        Node* m = n->right;
        assert(m != NULL);
        Node *a = n->left;
        Node *b = m->left;
        Node *c = m->right;
        
        // relink
        n->right = b;
        m->left = n;
        if (p!=NULL){
            if (p->left == n) p->left = m;
            else p->right = m;
        }
        else{
            root = m;
        }
        if (b != NULL) b->parent = n;
        n->parent = m;
        m->parent = p;

        // recalculate size
        n->size = get_size(a) + get_size(b) + 1;
        m->size = get_size(n) + get_size(c) + 1;
    } 

    void right_rotate(Node* n){
#ifndef NDEBUG
        std::cout << "right rotate" << std::endl;
#endif
        Node* p = n->parent;
        Node* m = n->left;
        assert(m != NULL);
        Node* a = m->left;
        Node* b = m->right;
        Node* c = n->right;

        // relink
        n->left = b;
        m->right = n;
        if (p!=NULL){
            if (p->left == n) p->left = m;
            else p->right = m;
        }
        else{
            root = m;
        }
        if (b != NULL) b->parent = n;
        n->parent = m;
        m->parent = p;
        
        // recalculate size
        n->size = get_size(b) + get_size(c) + 1;
        m->size = get_size(n) + get_size(a) + 1;
    }

    /*
     * insert 
     */
    void insert(int value){
        Node* n = new Node(value);
#ifndef NDEBUG
        printf("address of n: %p\n",n);
#endif
        if (root == NULL) {
            root = n;
            root->color = BLACK;
            return;
        }
        insert_into_subtree(root, n);
#ifndef NDEBUG
        printf("address of n: %p\n",n);
        printf("before rebalance color of n: %d\n", n->color);
        printf("color BLACK: %d\n", BLACK);
        printf("color RED: %d\n", RED);
#endif
        insert_rebalance(n);
    }

    void insert_into_subtree(Node* p, Node* n){
        assert(p!=NULL && n!=NULL && n->color == RED);
        p->size += 1;
        if (n->data <= p->data){
            // insert into left sub tree
            if (p->left != NULL) insert_into_subtree(p->left, n);
            else {
                p->left = n;
                n->parent = p;
            }
        }
        else{
            // insert into right sub tree
            if (p->right != NULL) insert_into_subtree(p->right, n);
            else{
                p->right = n;
                n->parent = p;
            }
        }
    }

    void insert_rebalance(Node *n){
#ifndef NDEBUG
        printf("rebalance %p\n", n);
        printf("\tcolor %d\n", n->color);
        printf("\troot is %p\n", root);
        printf("\tparenet is %p\n", n->parent); 
#endif
        assert(n!=NULL);
        assert(n->color == RED);
        // case 1, n is root
        if ( n == root ) {
            n->color = BLACK;
            return;
        }
        // n is not root, then its parenet p must exist
        Node *p = n->parent;
        assert(p!=NULL);

        // case 2, p is black
        if (p->color == BLACK) return;

        // if p is red, then p can not be root
        // therefore p's parent g must exist and must be black
        assert(p->color == RED);
        Node *g = p->parent;
        assert(g != NULL && g->color == BLACK);
        Node *u = get_sibling(p);
        if (u != NULL && u->color == RED){
            // case 3, u is red
                #ifndef NDEBUG
                    printf("case 3\n");
                #endif
            u->color = p->color = BLACK;
            g->color = RED;
            insert_rebalance(g);
        }
        else {
            // case 4, u is black, note null also means black 
            // case 4.1) n is not an out node of p, i.e. g to p and p to n form a turn
            // convert into case 4.2
            if (p == g->left && n == p->right){
                #ifndef NDEBUG
                    printf("case 4.1\n");
                #endif
                left_rotate(p);
                insert_rebalance(p);
                return;
            }
            if (p == g->right && n == p->left){
                #ifndef NDEBUG
                    printf("case 4.1\n");
                #endif
                right_rotate(p);
                insert_rebalance(p);
                return;
            }
            // case 4.2) n is an out node of p. i.e. g to p and p to n are smooth
            #ifndef NDEBUG
                printf("case 4.2\n");
            #endif
            p->color = BLACK;
            g->color = RED;
            if (p == g->left) right_rotate(g);
            else left_rotate(g);
        }
    }

    /*
     * erase 
     */
    bool erase(T value){
        if (!contain(value)) return false;
        erase(find_exact(root, value)); 
        return true;
    }

    void erase_update_size(Node *n){
        if (n == NULL) return;
        --n->size;
        erase_update_size(n->parent);
    }

    void erase(Node *n){
        assert(n != NULL);
        // if n has two children
        // transform into at most one children case
        if (n->left != NULL && n->right != NULL){
            Node* s = get_max_node(n->left);
            T tmp = s->data;
            s->data = n->data;
            n->data = tmp;
            erase(s);
            return;
        }
        // update size info 
        erase_update_size(n);
#ifndef NDEBUG
        printf("ERASE: \ndata of n: %d\n", n->data);
        printf("size updated\n");
        printf("root: %p\n",root);
        printf("to delete: %p\n",n);
        printf("color of n: %d\n", n->color);
#endif
        Node* c = (n->left == NULL?n->right:n->left);
        // replace n's place by c
        Node* p = n->parent;
        if (c != NULL) c->parent = p;
        if (p!=NULL){
            if (p->left == n) p->left = c;
            else p->right = c;
        }
        else {
            // erase the root
            root = NULL;
            delete n;
            return;
        }
#ifndef NDEBUG
        printf("replace n by c done\n");
        printf("c: %p\n", c);
        printf("color of c: %d\n", get_color(c));
#endif
            
        // simple case 1: n is red, do nothing
        // simple case 2: n is black but c is red, change c to black
        if (n->color == BLACK){
            if ( c != NULL && c->color == RED){
                c->color = BLACK;
            }
            else{
                // both n and c are black
                // black depth through c is reduced by 1
                if (c == NULL) erase_rebalance(p);
                else erase_rebalance(c);
            }
        }

#ifndef NDEBUG
        printf("to delete\n");
#endif
        delete n;
    }

    void erase_rebalance(Node* n){
#ifndef NDEBUG
        printf("erase rebalance %p\n", n);
#endif
        assert(n != NULL && n->color == BLACK);
        // case 1, n is the root
        if (n->parent == NULL) return;
        Node* p = n->parent;
        Node* s = get_sibling(n);
        // because n is black, n's sibling must exist
        assert(p!=NULL && s!=NULL);
        Node* sl = s->left;
        Node* sr = s->right;
        // note, sl, sr might be null
        // case 2: p,s,sl,sr are all black
        // repaint s to red and recursion on p
        if (p->color == BLACK && s->color == BLACK 
                && get_color(sl)==BLACK && get_color(sr)==BLACK){
            s->color = RED;
            erase_rebalance(p);
            return;
        }
        // case 3: s is red, p,sl,sr must be black
        // swap color of s, p, rotate on p so that s is new root
        if (s->color == RED){
            s->color = BLACK;
            p->color = RED;
            if (p->left == s) right_rotate(p);
            else left_rotate(p);
            return;
        }
        // case 4: p is red, s, sl, sr are all black
        // swap color of s, p
        if (p->color == RED && s->color == BLACK 
                && get_color(sl) == BLACK && get_color(sr) == BLACK){
            p->color = BLACK;
            s->color = RED;
            return;
        }
        // case 5: s is black, outer child of s is red, 
        // in this case, inner child and p can be any color
        // paint s with p's color, paint p, the outer child of s black 
        // rotate p so that s is the new root  
        if (s->color == BLACK && p->left==s && get_color(sl) == RED){ 
            s->color = p->color;
            p->color = sl->color = BLACK;
            right_rotate(p);
            return;
        }
        if (s->color == BLACK && p->right==s && get_color(sr) == RED){
            s->color = p->color;
            p->color = sr->color = BLACK;
            left_rotate(p);
            return;
        }
        // case 6: the remaining case, which is 
        // s is black, the outer child is black, the inner child is red
        // paint s to red and innter child to black
        // rotate s so that inner child is the new root
        // the case become case 5, recursion on n
        if (p->left == s){
            assert(sr->color == RED);
            s->color = RED;
            sr->color = BLACK;
            left_rotate(s);
            erase_rebalance(n);
        }
        else{
            assert(sl->color == RED);
            s->color = RED;
            sl->color = BLACK;
            right_rotate(s);
            erase_rebalance(n);
        }
    }

    /*
     * TODO: size related operations 
     */
    int count_less_than(T value){
        return count_less_than(root, value);
    }

    int count_less_than(Node* n, T value){
        if (n == NULL) return 0;
        if (n->data < value) 
            return get_size(n->left) + 1 + count_less_than(n->right, value);
        else 
            return count_less_than(n->left, value);
    }

    int size(){
        if (root == NULL) return 0;
        else return root->size;
    }

    int get_size(Node* n){
        if (n == NULL) return 0;
        else return n->size;
    }

    /*
     * find methods
     */
    Node* find_exact(Node* n, T value){
        if ( n == NULL) return NULL;
        if (n->data == value) return n;
        else if (n->data > value) return find_exact(n->left, value);
        else return find_exact(n->right, value);
    }

    Node* find_less_than(Node* n, T value){
        // find the right-most data stored which is strictly less than value
        if ( n == NULL) return NULL;
        if ( n->data < value) {
            Node* p = find_less_than(n->right, value);
            return (p==NULL?n:p);
        }
        else{
            return find_less_than(n->left, value);
        }
    }

    Node* find_leq(Node* n, T value){
        // find the right-most data stored which is less than or equal to value
        // similar to find_less_than
        if (n == NULL) return NULL;
        if ( n->data <= value){
            Node* p = find_leq(n->right, value);
            return (p==NULL?n:p);
        }
        else {
            return find_leq(n->left, value);
        }
    }

    Node* find_greater_than(Node* n, T value){
        if ( n == NULL) return NULL;
        if ( n->data > value){
            Node* p = find_greater_than(n->left, value);
            return (p == NULL?n:p);
        }
        else {
            return find_greater_than(n->right, value);
        }
    }

    Node* find_geq(Node* n, T value){
        if ( n == NULL) return NULL;
        if ( n->data >= value){
            Node* p = find_geq(n->left, value);
            return (p == NULL?n:p);
        }
        else {
            return find_geq(n->right, value);
        }
    }
    
    bool contain(T value){
        return (find_exact(root, value) != NULL);
    }

    /*
     * get min node, max node, successor, predecessor
     */
    Node* get_min_node(){
        return get_min_node(root);
    }

    Node* get_min_node(Node* n){
        if ( n == NULL) return NULL;
        if ( n->left == NULL) return n;
        return get_min_node(n->left);
    }

    Node* get_max_node(){
        return get_max_node(root);
    }

    Node* get_max_node(Node* n){
        if (n == NULL) return NULL;
        if (n->right == NULL) return n;
        return get_max_node(n->right);
    }

    Node* get_successor(Node* n){
        assert( n != NULL);
        // if right sub-tree is not empty, get min from right sub-tree
        if ( n->right != NULL) return get_min_node(n->right);
        // find upwards until a right turn
        Node* p = n->parent;
        while (p != NULL && p->right == n){
            p = p->parent;
            n = n->parent;
        }
        return p;
    }

    Node* get_predecessor(Node* n){
        assert( n!= NULL );
        // if left sub-tree is not empty, get max from left sub-tree
        if (n->left != NULL) return get_max_node(n->left);
        // find upwards until a left turn
        Node* p = n->parent;
        while ( p!=NULL && p->left == n){
            p = p->parent;
            n = n->parent;
        }
        return p;
    }
};

#endif

class Solution {
public:
    int reversePairs(vector<int>& a) {
        RbTree<long long> s;
        int ans = 0;
        for (auto x : a){
            long long tmp = x;
            ans += s.size() - s.count_less_than(2*tmp+1);
            s.insert(x);
        }
        return ans;
    }
};
