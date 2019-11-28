class Solution {
public:
    int minMoves2(vector<int>& a) {
        if (a.size() < 2) return 0;
        int n = a.size();
        sort(a.begin(), a.end());
        int pos = a[n/2];
        int ans = 0;
        for (int x : a)
            ans += abs(x-pos);
        return ans;
    }
};
