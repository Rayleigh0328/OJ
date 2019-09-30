template <typename T>
bool heap_cmp_min(T a, T b){
    return (a <= b);
}

template <typename T>
bool heap_cmp_max(T a, T b){
    return (a >= b);
}

template <typename T>
class Heap{

    std::vector<int> a;
    bool (*cmp)(T, T); 

    int parent(int k){
        if (k == 0) return -1;
        return (k-1)/2;
    }
    
    int left_child(int k){
        return 2*k + 1;
    }

    int right_child(int k){
        return 2*k + 2;
    }

    void swap_index(int x, int y){
        T tmp = a[x];
        a[x] = a[y];
        a[y] = tmp;
    }
    
    void down_heapfy(int k){
        int lc = left_child(k);
        int rc = right_child(k);

        // no child
        if (!is_valid_index(lc) && !is_valid_index(rc)) return;

        // only left
        if (is_valid_index(lc) && !is_valid_index(rc)) {
            if (!cmp(a[k], a[lc])) swap_index(k,lc);
            return;
        }
        
        // both child
        if (cmp(a[k], a[lc]) && cmp(a[k],a[rc])) return;
        if (cmp(a[lc], a[k]) && cmp(a[lc],a[rc])){
            swap_index(k,lc);
            down_heapfy(lc);
        } else {
            swap_index(k, rc);
            down_heapfy(rc);
        }

    }

    void up_heapfy(int k){
        int fa = parent(k);
        if (fa == -1) return;
        if (!cmp(a[fa], a[k])) { 
            swap_index(fa,k);
            up_heapfy(fa);
        }
    }

public:

    void verify(){
        for (int i=0;i<a.size();++i){
            int lc = left_child(i);
            int rc = right_child(i);
            if ( (is_valid_index(lc) && !cmp(a[i], a[lc]) ) || 
                 (is_valid_index(rc) && !cmp(a[i], a[rc]))) 
            {
                printf("index %d is BAD with parent:%d lc:%d rc:%d\n", i, a[i], a[lc], a[rc]);
            }
        }
    }

    Heap(){
        cmp = heap_cmp_min;
    }

    Heap( bool (*f)(T, T) ){
        cmp = f;
    }

    bool empty(){
        return (a.size() == 0);
    }
    
    int size(){
        return a.size();
    }

    bool is_valid_index(int k){
        return (0<=k && k < a.size());
    }

    T get_root(){
        return a[0];
    }
    
    bool erase(int k){ 
        if (!is_valid_index(k)) return false; 
        swap_index(k, a.size()-1);
        a.pop_back();
        down_heapfy(k);
        return true;
    }

    T extract_root(){
        T result = a[0];
        erase(0);
        return result;
    }

    void insert(T data){
        a.push_back(data);
        up_heapfy(a.size()-1);
    }

};

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        Heap<int> heap(heap_cmp_max);
        for (auto x : stones) heap.insert(x);
        int s1, s2;
        while (heap.size() >= 2){
            s1 = heap.extract_root();
            s2 = heap.extract_root();
            if (s1 - s2 > 0) heap.insert(s1 - s2);
        }
        if (heap.empty()) return 0;
        else return heap.extract_root();
    }
};
