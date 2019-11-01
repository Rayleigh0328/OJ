class Solution {
    
    static const int MAX_LENGTH = 9;
    int tot_cnt[MAX_LENGTH + 1];
    int one_cnt[MAX_LENGTH + 1];
    
    void preprocess(){
        tot_cnt[0] = 1;
        one_cnt[0] = 0;
        for (int i=1;i<=MAX_LENGTH;++i){
            tot_cnt[i] = tot_cnt[i-1] * 10;
            one_cnt[i] = one_cnt[i-1] * 10 + tot_cnt[i-1];
        }
    }
    
    int solve(int n, int base, int len){
        if (n == 0) return 0;
        int high = n / base;
        int tail = n % base;
        
        if (high == 0) return solve(tail, base/10, len-1);
        if (high == 1)
            return (tail+1 + one_cnt[len-1] + solve(tail, base/10, len-1));
        return tot_cnt[len-1] + high * one_cnt[len-1] + solve(tail, base/10, len-1);
    }
    
public:
    int countDigitOne(int n) {
        preprocess();
        if (n <= 0) return 0;
        int base = 1;
        int len = 1;
        while (n / base / 10> 0){
            base *= 10;
            ++len;
        }
        // cout << base << " " << len << endl;
        return solve(n, base, len);
    }
};
