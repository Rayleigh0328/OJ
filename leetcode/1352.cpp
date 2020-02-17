
class ProductOfNumbers {
    const int size = (1<<16);
    vector<int> seg;
    vector<int> left;
    vector<int> right;
    int tail = 0;
    
    int lc(int k){
        return k * 2;
    }
    
    int rc(int k){
        return k * 2 + 1;
    }
    
    int parent(int k){
        return k / 2;
    }
    
public:
    ProductOfNumbers() {
        seg = vector<int>(2*size, 1);
        left = vector<int>(2*size, 1);
        right = vector<int>(2*size, 1);
        for (int i=size; i<2*size; ++i){
            left[i]=right[i]=i-size;
        }
        for (int i=size-1;i>=1;--i){
            left[i] = left[lc(i)];
            right[i] = right[rc(i)];
        }
    }
    
    void add(int num) {
        int cur = tail++ + size;
        while (cur != 0){
            seg[cur] *= num;
            cur = parent(cur);
        }
    }
    
    int search(int index, int L, int R){
        if (R < left[index]) return 1;
        if (L > right[index]) return 1;
        if (L == left[index] && R == right[index]) return seg[index];
        int left_child = lc(index);
        int right_child = rc(index);
        int result = search( left_child, L, min(R, right[left_child])) * search(right_child, max(L, left[right_child]), R);
        return result;
    }
    
    int getProduct(int k) {
        int L = tail-k;
        int R = tail-1;
        return search(1,L,R);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
