class Solution {
    
    vector<string> construct(const string& s, const unordered_set<string> &dict, const vector<bool>& f, int len){
        if (len == 0) return {""};
        vector<string> result;
        for (int j=0;j<len;++j)
            if (f[j] && dict.find(s.substr(j,len-j)) != dict.end()){
                vector<string> prefixes = construct(s,dict,f,j);
                for (const auto & prefix : prefixes)
                    result.push_back(prefix + s.substr(j,len-j) + " ");
            }
        return result;
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return {""}; 
        
        unordered_set<string> dict;
        for (const auto & e : wordDict) dict.emplace(e);
        
        int n = s.length();
        vector<bool> f(n+1,false);
        f[0] = true;
        
        for (int i=1;i<=n;++i)
            for (int j=0;j<i;++j)
                if (dict.find(s.substr(j,i-j))!=dict.end() && f[j]) {
                    f[i] = true;
                    break;
                }
        if (!f[n]) return {};
        vector<string> result = construct(s,dict,f,n);
        for (auto &e : result)
            if (!e.empty()) e.pop_back();
        return result;
    }
};
