class Solution {
public:
    
    int available;
    int ans_count;
    int n;
    
    void solve(int pos){
        if (pos == 1){
            ++ans_count;
            return;
        }
        for (int i=1; i<=n; ++i){
            if ((available & (1<<i)) && (pos % i == 0 || i % pos == 0)) {
                available ^= (1<<i);
                solve(pos - 1);
                available ^= (1<<i);
            }
        }
    }
    
    int countArrangement(int x) {
        n = x;
        available = (1<<20) -1;
        ans_count = 0;
        solve(n);
        return ans_count;
    }
};
