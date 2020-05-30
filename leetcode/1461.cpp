class Solution {
public:
    bool hasAllCodes(string s, int k) {
        const int n = s.size();
        vector<bool> flag((1<<k), false);
        if (n < k) return false;
        
        // construct first number
        int cur = 0;
        for (int i=0;i<k;++i) cur = cur * 2 + (s[i] - '0');
        flag[cur] = true;
        // printf("%d\n", cur);
        // construct following numbers
        for (int i=k; i<n; ++i){
            // printf("process %c\n", s[i]);
            cur = (cur - ((s[i-k] - '0') << (k-1))) * 2 + (s[i]-'0');
            // printf("%d\n", cur);
            flag[cur] = true;
        }
        
        // check result
        for (int i=0;i<(1<<k);++i)
            if (!flag[i]) return false;
        return true;
    }
};
