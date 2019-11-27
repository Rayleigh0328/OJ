class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int p1 = 0, p2 = 0, ans = 0;
        while (p1 < g.size() && p2 < s.size()){
            if (s[p2] >= g[p1]) {++p1; ++p2; ++ans;}
            else ++p2;
        }
        return ans;
    }
};
