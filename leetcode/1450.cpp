class Solution {
public:
    int busyStudent(vector<int>& s, vector<int>& t, int q) {
        int result = 0;
        const int n = s.size();
        for (int i=0;i<n;++i)
            if (s[i] <= q && q <= t[i]) ++result;
        return result;
    }
};
