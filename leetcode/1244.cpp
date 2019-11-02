struct TreapNode{
    
    TreapNode* left;
    TreapNode* right;
    
    int key;
    int priority;
    int size;
    int sum;
    
    TreapNode(int k, int p):
        key(k),
        priority(p),
        size(1),
        sum(k),
        left(NULL),
        right(NULL)
    {
    }
};

struct Treap{
    
    typedef pair<TreapNode*, TreapNode*> TreapPair;
    TreapNode* root;
    
    Treap():
        root(NULL)
    {
    }
    
    ~Treap(){
        delete_subtree(root);
    }
    
    int get_sum(TreapNode* u){
        if (u == NULL) return 0;
        else return u->sum;
    }
    
    int get_size(TreapNode* u){
        if (u == NULL) return 0;
        else return u->size;
    }
    
    // split u into two treap x, y
    // such that keys in x are all <= target
    // and keys in y are all > target
    TreapPair split(TreapNode* u, int target){
        if (u == NULL) return {NULL, NULL};
        TreapPair tp;
        if (u->key <= target){
            u->sum -= get_sum(u->right);
            u->size -= get_size(u->right);
            tp = split(u->right, target);
            u->right = tp.first;
            u->sum += get_sum(tp.first);
            u->size += get_size(tp.first);
            return {u, tp.second};
        }
        else {
            u->sum -= get_sum(u->left);
            u->size -= get_size(u->left);
            tp = split(u->left, target);
            u->left = tp.second;
            u->sum += get_sum(tp.second);
            u->size += get_size(tp.second);
            return {tp.first, u};
        }
    }
    
    // merge two treap where max key in u < min key in v
    TreapNode* merge(TreapNode* u, TreapNode* v){
        if (u == NULL) return v;
        if (v == NULL) return u;
        TreapNode* tmp;
        if (u->priority > v->priority) {
            u->sum -= get_sum(u->right);
            u->size -= get_size(u->right);
            tmp = merge(u->right, v);
            u->right = tmp;
            u->sum += get_sum(tmp);
            u->size += get_size(tmp);
            return u;
        }
        else {
            v->sum -= get_sum(v->left);
            v->size -= get_size(v->left);
            tmp = merge(u, v->left);
            v->left = tmp;
            v->sum += get_sum(tmp);
            v->size += get_size(tmp);
            return v;
        }
    }
    
    TreapNode* find(TreapNode* u, int k){
        if (u == NULL) return NULL;
        if (k == u->key) return u;
        if (k < u->key) return find(u->left, k);
        else return find(u->right, k);
    }
    
    TreapNode* find(int k){
        return find(root, k);
    }
    
    void insert(int k){
        TreapNode* new_treap = new TreapNode(k, rand());
        TreapPair tp = split(root, k);
        root = merge(merge(tp.first, new_treap) , tp.second);
    }
    
    void delete_subtree(TreapNode* u){
        if (u == NULL) return;
        delete_subtree(u->left);
        delete_subtree(u->right);
        delete u;
    }
    
    // this operation will erase all the nodes with key k
    void erase_all(int k){
        if (find(k) == NULL) return;
        TreapPair tp1 = split(root, k);
        TreapPair tp2 = split(tp1.first, k-1);
        delete_subtree(tp2.second);
        root = merge(tp2.first, tp1.second);
    }
    
    void erase_one(int k){
        TreapNode* u = find(k);
        if (u == NULL) return;
        erase(u);
    }
    
    void erase(TreapNode* u){
        if (u == root){
            root = merge(u->left, u->right);
            return;
        }
        
        TreapNode* p = root;
        while (p->left != u && p->right != u){
            p->size -= 1;
            p->sum -= u->key;
            if (u->key <= p->key) p = p->left;
            else p=p->right;
        }
        p->size -= 1;
        p->sum -= u->key;
        assert(p->left == u || p->right == u);
        
        if (p->left == u)
            p->left = merge(u->left, u->right);
        else 
            p->right = merge(u->left, u->right);
    }
    
    int get_largest_k_sum(TreapNode* u, int count){
        assert(get_size(u) >= count);
        if (get_size(u) == count) return get_sum(u);
        if (count <= get_size(u->right))
            return get_largest_k_sum(u->right, count);
        count -= get_size(u->right);
        int result = get_sum(u->right);
        if (count == 1) return result + u->key;
        count--;
        result += u->key;
        return result + get_largest_k_sum(u->left, count);
    }
    
//     void print(){
//         printf("=======================\n");
//         print(root);
//         printf("=======================\n");
//     }
    
//     void print(TreapNode* u){
//         if (u == NULL) return;
//         printf("%p:(key:%d, priority: %d, size: %d, sum: %d, left:%p, right: %p)\n", u, u->key, u->priority, u->size, u->sum, u->left,u->right);
//         print(u->left);
//         print(u->right);
//     }
};

class Leaderboard {

    Treap treap;
    unordered_map<int, int> player_to_score;
    
public:
    Leaderboard() {
    }
    
    void addScore(int playerId, int score) {
        // printf("add %d to %d\n", score, playerId);
        int old_score;
        if (player_to_score.find(playerId) == player_to_score.end()) old_score = 0;
        else {
            old_score = player_to_score[playerId];
            treap.erase_one(old_score);
        }
        // printf("old score %d removed\n", old_score);
        int new_score = old_score + score;
        player_to_score[playerId] = new_score;
        treap.insert(new_score);
    }
    
    int top(int count) {
        // printf("get top %d\n", count);
        if (count >= treap.get_size(treap.root)) return treap.get_sum(treap.root);
        return treap.get_largest_k_sum(treap.root, count);
    }
    
    void reset(int playerId) {
        // printf("reset %d\n", playerId);
        int old_score = 0;
        if (player_to_score.find(playerId) != player_to_score.end())
            old_score = player_to_score[playerId];
        addScore(playerId, -old_score);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
