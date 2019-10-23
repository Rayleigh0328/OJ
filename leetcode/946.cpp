class Solution {
    int n;
    unordered_map<int,int> pos;
    bool match(const vector<int> &a, int i, int j, const vector<int> &b, int p, int q){
        // printf("check [%d,%d) against [%d,%d)\n", i,j,p,q);
        if (i==j) return (p==q);
        if (p==q) return (i==j);
        if (j-i != q-p) return false;
        int s = pos[a[i]];
        if(s<p || s>=q) return false;
        int t = s - p + (i+1);
        return match(a, i+1, t, b, p, s) && match(a, t, j, b, s+1, q);
    }
    
public:
    bool validateStackSequences(vector<int>& a, vector<int>& b) {
        n = a.size();
        if (b.size() != n) return false;
        for (int i=0;i<n;++i) pos[b[i]] = i;
        return match(a,0,n,b,0,n);
    }
};
