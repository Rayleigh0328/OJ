class Solution {
    
    const int mode = 1000000007;
    
public:
    int countPalindromicSubsequences(string s) {
        
        const int n = s.size();
        
        vector<int> next(n,-1);
        vector<int> prev(n,-1);
        unordered_map<char, int> pos;
        for (int i=0;i<n;++i){
            char ch = s[i];
            if (pos.find(ch) != pos.end()){
                next[pos[ch]] = i;
                prev[i] = pos[ch];
            }
            pos[ch] = i;
        }
        
        vector<vector<long long>> f(n, vector<long long>(n,0));
        int j, low, high;
        for (int i=0;i<n;++i) f[i][i] = 1;
        for (int len = 2; len <=n; ++len)
            for (int i=0;i<n;++i){
                j = i + len - 1;
                if (j >= n) break;
                
                if (s[i] != s[j]) {
                    f[i][j] = (f[i+1][j] + f[i][j-1] - f[i+1][j-1] + mode) % mode;
                    continue;
                }
                
                low = next[i];
                high = prev[j];
                // printf("i:%d, j: %d, low: %d, high %d\n", i,j, low, high);
                if (low == j) f[i][j] = (f[i+1][j-1] * 2 + 2 + mode) % mode; 
                else if (low == high) f[i][j] = (f[i+1][j-1] * 2 + 1 + mode) % mode;
                else f[i][j] = (f[i+1][j-1] * 2 - f[low+1][high-1] + mode) % mode;
            }
        
        return f[0][n-1];
    }
};
