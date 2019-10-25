vector<int> kmp(string s, string p){
    // add -1 into p, -1 can not be in s
    p.push_back(-1);
    int n = s.length();
    int m = p.length();

    // construct function phi
    vector<int> phi(m);
    int i = 0, j = -1;
    phi[0] = -1;
    while (i < m-1){
        if (p[i+1] == p[j+1]) phi[++i] = ++j;
        else if (j >= 0) j = phi[j];
        else phi[++i] = -1;
    }

    // optimized fuction phi
    for (int i=0;i<m-1;++i)
        while (phi[i] != -1 && p[i+1] == p[phi[i]+1]) phi[i] = phi[phi[i]];

    // match p against s
    vector<int> f(n);
    i = -1; j = -1;
    while (i < n-1){
        if (s[i+1] == p[j+1]) f[++i] = ++j;
        else if (j >= 0) j = phi[j];
        else f[++i] = -1;
    }

    vector<int> ans;
    for (int i=0;i<n;++i)
        if (f[i] == m-2) ans.push_back(i - m + 2);
    return ans;
}


class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> ans = kmp(haystack, needle);
        if (needle.empty()) return 0;
        if (ans.empty()) return -1;
        else return ans[0];
    }
};
