class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        vector<int> f(n, -1);
        for (int i=1;i<n;++i){
            if (s[i] != s[i-1]) f[i] = i-1;
            else if (f[i-1] - 1 >= 0 && s[f[i-1] - 1] == s[f[i-1]]) f[i] = f[i-1] - 1;
        }
        // for (auto x : f) cout << x << " "; cout << endl;
        int ans=0;
        for (int i=0;i<n;++i)
            ans += (f[i]>=0?1:0);
        return ans;
    }
};
