class Solution {
    static const int MAX_SIZE = 1005;
    static const int ALPHABET_SIZE = 256;
    static const int inf = (1<<28);
    
    typedef set<int, greater<int>> MySet;
    vector<MySet> pos_set = vector<MySet>(ALPHABET_SIZE);
    int f[MAX_SIZE][MAX_SIZE];
    int from[MAX_SIZE][MAX_SIZE];
    string a;
    string b;
    int n;
    int m;
    
    int find(const MySet& s, int k){
        auto it = s.upper_bound(k);
        if (it == s.end()) return -1;
        return *it;
    }
    
    int solve(int i, int j){

        if (i == 0) return j;
        if (j == 0) return i;
        // memorization
        if (f[i][j] != inf) return f[i][j];

        char ch = b[j-1];
        // case 1: match ch in a[0..i-1]
        int pos = find(pos_set[ch], i);
        
        if (pos != -1 && i-pos + solve(pos,j-1) < f[i][j]){
            f[i][j] = i-pos + solve(pos,j-1);
            from[i][j] = pos;
        }
        // case 2: append ch to the solution of a[0..i-1] to b[0..j-1],
        if (1 + solve(i,j-1) < f[i][j]){
            f[i][j] = 1 + solve(i,j-1);
            from[i][j] = i;
        }
        return f[i][j];
    }
    
    string reconstruct_ans(int i, int j){
        if (i == 0) return b.substr(0,j);
        if (j == 0) return a.substr(0,i);
        if (from[i][j] == i){
            return reconstruct_ans(i,j-1) + b[j-1];
        }
        else{
            int pos = from[i][j];
            return reconstruct_ans(pos, j-1) + a.substr(pos, i-pos);
        }
    }
    
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // init f to inf
        for (int i=0;i<MAX_SIZE;++i)
            for (int j=0;j<MAX_SIZE;++j){
                f[i][j] = inf;
                from[i][j] = -1;
            }
        a = str1; n = a.length();
        b = str2; m = b.length();
        
        // precompute positions for each character
        for (int i=0;i<n;++i) pos_set[a[i]].emplace(i);
        solve(n,m);
        return reconstruct_ans(n,m);
        return "";
    }
};
