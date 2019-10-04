class SegmentationTree{

    int n;
    int cap;
    int total_leaf; 
    vector<int> a;
    vector<int> left;
    vector<int> right;


    int left_child(int k){
        return 2 * k;
    }

    int right_child(int k){
        return 2*k + 1;
    }

    int parent(int k){
        return k/2;
    }

public:
    SegmentationTree(int size){
        n = size;

        int k = 0;
        while ((1<<k) < n) ++k;

        total_leaf = (1<<k);
        cap = (1<<(k+1));
        
        a = vector<int>(cap, 0);
        left = vector<int>(cap);
        right = vector<int>(cap);

        for (int i=total_leaf; i<cap; ++i){
            left[i] = right[i] = i-total_leaf;
        }
        
        for (int i=total_leaf - 1; i>0; --i){
            left[i] = left[left_child(i)];
            right[i] = right[right_child(i)];
        }
    }
    
    void print(){
        for (int i=1;i<cap;++i)
            printf("node %d: [%d, %d] -> %d\n", i, left[i], right[i], a[i]);
    }
    
    void update(int node, int l, int r, int amount){
        // printf("update node %d, node range [%d, %d], update range[%d, %d]\n",
        //        node, left[node], right[node], l, r);
        if (l == left[node] && r == right[node]) {
            a[node] += amount;
            return;
        }
        int lc = left_child(node);
        int rc = right_child(node);
        if (l <= right[lc]) update(lc, l, min(right[lc],r), amount);
        if (r >= left[rc]) update(rc, max(l,left[rc]), r, amount);
    }

    void update(int l, int r, int amount) {
        // printf("update %d to %d with %d\n", l, r, amount);
        update(1, l, r, amount);
    }

    void push_down(){
        for (int i=1;i<total_leaf; ++i){
            a[left_child(i)] += a[i];
            a[right_child(i)] += a[i];
            a[i] = 0;
        }
    }

    int get(int k){
        return a[k + total_leaf];
    }

};



class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        SegmentationTree st(n);
        for (auto e : bookings){
            st.update(e[0]-1, e[1]-1, e[2]);
        }
        
        st.push_down();
        vector<int> ans;
        for (int i=0;i<n;++i)
            ans.push_back(st.get(i));
        return ans;
    }
};
