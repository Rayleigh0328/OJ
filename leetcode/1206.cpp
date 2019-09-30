class Skiplist {
    
template<typename T>
class SkipList{

    struct SkipListNode{
        T data;
        std::vector<SkipListNode*> next;
        std::vector<SkipListNode*> prev;
        std::vector<int> span;

        SkipListNode(T d){
            data = d;
            next.push_back(NULL);
            prev.push_back(NULL);
            span.push_back(0);
        }
    };

    SkipListNode *head;
    int total_level;
    double raise_level_threshold;

public:
    SkipList(){
        SkipList(0.25);
    }
    
    SkipList(double threshold){
        head = new SkipListNode(-1);
        total_level = 1;
        raise_level_threshold = threshold;
    }

//     void print(SkipListNode* p){
//         printf("addr: %p, data: %d\t", p, p->data);
//         for (int i=0; i< p->next.size(); ++i)
//            printf("lvl %d next: %p\t\t\t", i, p->next[i]);
//         printf("\n");
//     }

//     void print(){
//         printf("=================\n");
//         printf("total level:%d\n", total_level);
//         SkipListNode *p = head;
//         while (p != NULL){
//             print(p);
//             p = p->next[0];
//         }
//         printf("=================\n");
//     }

    SkipListNode* find(const T &target, SkipListNode* p, int level){
        if (level < 0) return NULL;
        SkipListNode *q = p->next[level];
        if (q == NULL || q->data > target) 
            return find (target, p, level - 1);
        else if (q->data == target) 
            return q;
        else 
            return find(target, q, level);
    }

    SkipListNode* find(const T &target){
        return find(target, head, total_level - 1);
    }

    SkipListNode* lower_bound(const T &target, SkipListNode* p, int level){
        if (level < 0) return p;
        SkipListNode *q = p->next[level];
        if (q == NULL || q->data >= target) 
            return lower_bound(target, p, level - 1);
        else 
            return lower_bound(target, q, level);
    }

    SkipListNode* lower_bound(const T &target){
        return lower_bound(target, head, total_level -1);
    }

    void link(SkipListNode *prev_node, SkipListNode* current_node, int level){
        SkipListNode* next_node = prev_node->next[level];
        prev_node->next[level] = current_node;
        current_node->prev[level] = prev_node;
        current_node->next[level] = next_node;
        if (next_node != NULL) next_node->prev[level] = current_node;
    }

    void insert(T data){
        SkipListNode* prev_node = lower_bound(data);
        SkipListNode* current_node = new SkipListNode(data);
        int level = 0;
        link(prev_node, current_node, level);
        while (rand() / (RAND_MAX + 1.0) < raise_level_threshold ){
            while (prev_node->next.size()  - 1 < level + 1) {
                if (prev_node == head) {
                    head->next.push_back(NULL);
                    head->prev.push_back(NULL);
                    ++total_level;
                    //head->span.push_back(head->span.get_back());
                }
                else{
                    prev_node = prev_node->prev[level];
                }
            }
            current_node->next.push_back(NULL);
            current_node->prev.push_back(NULL);
            // print();
            link(prev_node, current_node, ++level);
        }
    }

    bool erase(T data){
        if (find(data) == NULL) return false;
        erase(find(data));
        return true;
    }
    
    void unlink(SkipListNode* prev_node, SkipListNode* current_node, int level){
        SkipListNode* next_node = current_node->next[level];
        prev_node->next[level] = next_node;
        if (next_node != NULL) next_node->prev[level] = prev_node;
    }

    void erase(SkipListNode* p){
        SkipListNode *prev_node;
        SkipListNode *next_node;
        for (int level=0; level<p->next.size(); ++level){
            prev_node = p->prev[level];
            next_node = p->next[level];
            unlink(prev_node, p, level);
        }
        delete p;
    }
};

    SkipList<int> list;
public:
    
    Skiplist() {
        list = SkipList<int>(0.25);
    }
    
    bool search(int target) {
        if (list.find(target) == NULL) return false;
        return true;
    }
    
    void add(int num) {
        list.insert(num);
    }
    
    bool erase(int num) {
        return list.erase(num);
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
