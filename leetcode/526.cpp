class Solution {
public:
    
    vector<bool> available;
    int ans_count;
    int n;
    
    void solve(int pos){
        if (pos == 1){
            ++ans_count;
            return;
        }
        for (int i=1; i<=n; ++i){
            if (available[i] && (pos % i == 0 || i % pos == 0)) {
                // cout<< pos <<" "<<i<< endl;
                available[i] = false;
                solve(pos - 1);
                available[i] = true;
            }
        }
    }
    
    int countArrangement(int x) {
        n = x;
        available.resize(n+1);
        for (int i=1; i<=n;++i) available[i] = true;
        ans_count = 0;
        solve(n);
        return ans_count;
    }
};
