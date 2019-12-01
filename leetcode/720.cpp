class Solution {
    
    int n;
    vector<string> a;
    vector<int> f;
    unordered_map<string, int> s;
    
    string get_better_one(string &s1, string &s2){
        if (s1.size() > s2.size()) return s1;
        if (s2.size() > s1.size()) return s2;
        if (s1 < s2) return s1;
        return s2;
    }
    
    int solve(int k){
        if (f[k] != -1) return f[k];
        if (a[k].size() == 1) return (f[k] = 1);
        string st = a[k].substr(0, a[k].size()-1);
        if (s.find(st) == s.end()) return (f[k] = 0);
        else return (f[k] = solve(s[st]));
    }
    
public:
    string longestWord(vector<string>& words) {
        a = words;
        n = a.size();
        f = vector<int>(n, -1);
        for (int i=0;i<n;++i) s.emplace(a[i], i);
        
        for (int i=0;i<n;++i) solve(i);
        // for (int i=0;i<n;++i) printf("f[%d] -> %d", i, f[i]);
        string result;
        for (int i=0;i<n;++i)
            if (f[i] == 1)
                result = get_better_one(result, a[i]);
        return result;
    }
};
