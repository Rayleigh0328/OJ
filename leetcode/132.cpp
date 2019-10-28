class Solution {
    bool is_palindrome(const string& s, int start, int end){
        for (int i=0;i<((end-start)>>1);++i)
            if (s[start+i] != s[end-1-i]) return false;
        return true;
    }
public:
    int minCut(string s) {
        // f[i] means min cut to partition s's prefix of length i
        // f[0] = 0
        if (s.empty()) return 0;
        int inf = (1<<30);
        int n = s.length();
        vector<int>f(n+1, inf);
        f[0] = 0;
        for (int i=1;i<=n;++i)
            for (int j=0;j<i;++j){
                if (is_palindrome(s,j,i))
                    f[i] = min(f[i], f[j] + 1);
            }
        return f[n]-1;
    }
};
