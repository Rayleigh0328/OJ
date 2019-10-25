class Solution {
    
    vector<vector<int>> f;
    string s, p;
    int n,m;
    
    bool solve(int i, int j){
        if (f[i][j] != -1) return f[i][j];
        if (i <= 0 || j <= 0) return false;
        if (p[j-1] == '*'){
            for (int k=0; k<=i;++k) 
                if (solve(k,j-1)) return f[i][j] = true;
            return f[i][j]=false;
        }
        if (p[j-1] == '?' || p[j-1] == s[i-1]) return f[i][j] = solve(i-1,j-1);
        return f[i][j] = false;
    }
    
    string simplify(const string &p){
        string result = "";
        for (auto ch : p){
            if(ch == '*' && !result.empty() && result.back()=='*') continue;
            result.push_back(ch);
        }
        return result;
    }
    
public:
    bool isMatch(string ss, string pp) {
        // f[i][j] denotes s's suffix of length i can match with p's suffix of length j
        // edge case f[0][0] = true
        // case 1: p[j] is * ==> f[k][j-1] k can be 0 to i
        // case 2: p[j] is ? ==> f[i-1][j-1]
        // case 3: s[i-1]==p[j-1] ==> f[i-1][j-1]
        // o.w. false
        s = ss;
        p = simplify(pp);
        // cout << p << endl;
        n = s.size();
        m = p.size();
        
        f = vector(n+1, vector<int>(m+1, -1));
        for (int i=0;i<=n;++i) f[i][0] = 0;
        for (int j=0;j<=m;++j) f[0][j] = 0;
        f[0][0] = 1;
        if (p[0] == '*') f[0][1] = 1;
        
        return solve(n,m);
    }
};
