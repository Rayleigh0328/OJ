class Solution {
    const double eps = 1e-8;
    
    bool check(const string &s, int len){
        for (int i=0;i<s.length();++i)
            if (s[i] != s[i % len]) return false;
        return true;
    }
    
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        if (n > 1 && check(s, 1)) return true;
        for (int i=2;i<=sqrt(n)+eps;++i)
            if (n % i == 0 && (check(s, i) || check(s, n / i))) return true;
        return false;
    }
};
