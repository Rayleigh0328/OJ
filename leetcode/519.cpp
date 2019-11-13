class Solution {
    int n,m;
    map<int,int> replaced;
    int current_index;
    
public:
    Solution(int n_rows, int n_cols) {
        n = n_rows;
        m = n_cols;
        reset();
        // srand(1);
    }
    
    vector<int> flip() {
        int pos = rand() % (current_index + 1);
        // printf("current index: %d, target position: %d\n", current_index, pos);
        // for (auto &e : replaced)
            // printf("repalce %d with %d\n", e.first, e.second);
        int result;
        if (replaced.find(pos) != replaced.end()) result = replaced[pos];
        else result = pos;
        
        if (replaced.find(current_index) == replaced.end())
            replaced[pos] = current_index;
        else 
            replaced[pos] = replaced[current_index];
        
        --current_index;
        
        return {result / m, result % m};
    }
    
    void reset() {
        replaced.clear();
        current_index = n * m - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
