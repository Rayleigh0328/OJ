class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p1 = 0, p2 = 0;
        while (p1 < s.length()){
            while (p2 < t.size() && t[p2] != s[p1]) ++p2;
            ++p1;
            if (p2++ == t.size()) return false;
        }
        return true;
    }
};
