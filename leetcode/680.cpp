class Solution {
    bool solve(const string& st, int left, int right){
        printf("solve %d %d\n", left, right);
        for (int i=0;i<right-left;++i)
            if (st[left+i] != st[right-i-1]) return false;
        return true;
    }
public:
    bool validPalindrome(string s) {
        if (solve(s,0,s.length())) return true;
        for (int i=0; i<s.length() / 2; ++i){
            if (s[i] != s[s.length()-i-1])
                return (solve(s,i+1, s.length()-i) || solve(s,i, s.length()-i-1));
        }
        return false;
    }
};
