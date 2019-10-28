class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // f[i] means the prefix of s of length i can be represented
        unordered_set<string> dict;
        for (const auto & e : wordDict) dict.emplace(e);
        
        int n = s.length();
        vector<bool> f(n+1,false);
        f[0] = true;
        for (int i=1;i<=n;++i)
            for (int j=0;j<i;++j)
                if (dict.find(s.substr(j,i-j))!=dict.end())
                    f[i] = f[i] || f[j];
        return f[n];
    }
};
