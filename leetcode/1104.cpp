class Solution {
    int get_parent(int k){
        return k/2;
    }
    
    int get_depth(int k){
        for (int i=0; ;++i){
            if (((1<<i) <= k) && (k < (1<<(i+1)))) return i;
        }
    }
    
    int map(int k, int depth){
        return 3*(1<<depth) - 1 - k;
    }
    
public:
    vector<int> pathInZigZagTree(int label) {
        // in a normal complete binary tree
        // label from 1
        // left child = parent * 2
        // right child = parent * 2 + 1
        // parent = child / 2
        
        // range of depth d, root is of depth 0
        // [2^d, 2^(d+1) - 1]
        // node numbered k is of depth d iff
        // 2^d <=k <2^(d+1)
        
        // odd depth is reverse labeled
        // create a 1-to-1 maping for odd level
        // k <---> 3 * 2^d - 1 - k
        
        // step1: process label, if it is in odd depth, map it
        int d = get_depth(label);
        if (d & 1) label = map(label, d);
        // step2: get a sequence in normal tree
        vector<int> ans;
        ans.push_back(label);
        int p = get_parent(label);
        while (p > 0){
            ans.push_back(p);
            p = get_parent(p);
        }
        reverse(ans.begin(), ans.end());
        
        // step3: map each odd element in previous sequence
        for (int i=0; i<ans.size();++i)
            if (i & 1) ans[i] = map(ans[i], i);
        return ans;
    }
};
