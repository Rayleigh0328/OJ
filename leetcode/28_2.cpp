bool check(int pos, const string &s, const string &p){
    for (int i=0;i<p.length();++i)
        if (s[pos+i] != p[i]) return false;
    return true;
}

vector<int> rabin_carp(const string &s, const string &p, int base, int mode){
    vector<int> ans;
    int n = s.length();
    int m = p.length();
    if (n < m) return ans;
    
    int current = 0, target = 0, h = 1;
    for (int i=0;i<m-1;++i) h = (h * base) % mode;
    for (int i=0;i<m;++i){
        current = (current * base + s[i]) % mode;
        target = (target * base + p[i]) % mode;
    }
    if (target == current && check(0,s,p)) ans.push_back(0);
    for (int i=1;i+m-1 < n;++i){
        int c1 = s[i-1];
        int c2 = s[i+m-1];
        current = ((current - c1 * h) * base + c2) % mode;
        current = (current + mode) % mode;
        if (current == target && check(i,s,p)) ans.push_back(i); 
    }
    return ans;
}

vector<int> rabin_carp(const string &s, const string &p){
    return rabin_carp(s,p, 256, 101);
}

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        vector<int> ans = rabin_carp(haystack, needle); 
        if (ans.empty()) return -1;
        else return ans[0];
    }
};
