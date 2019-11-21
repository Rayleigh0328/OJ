class Solution {
public:
    int countSegments(string s) {
        int pos = 0;
        int ans = 0;
        while (pos < s.length()){
            while (pos < s.length() && s[pos] == ' ') ++pos;
            if (pos == s.length()) break;
            ++ans;
            int next = pos;
            while (next<s.length() && s[next] != ' ') ++next;
            pos = next;
        }
        return ans;
    }
};
