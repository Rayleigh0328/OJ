class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if (s1.length() != s2.length()) return -1;
        int n = s1.length();
        int x_count=0, y_count=0;
        for (int i=0;i<n;++i)
            if (s1[i] != s2[i]){
                if (s1[i] == 'x') ++x_count;
                else ++y_count;
            }
        if ((x_count + y_count) & 1) return -1;
        int ans = (x_count & 1) + (y_count & 1) + x_count/2 + y_count/2;
        return ans;
    }
};
