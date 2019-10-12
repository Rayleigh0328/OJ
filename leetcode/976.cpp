class Solution {
public:
    int largestPerimeter(vector<int>& a) {
        int n = a.size();
        if (n < 3) return 0;
        sort(a.begin(), a.end());
        for (int i=n-1; i>=2;--i)
            if (a[i-2] + a[i-1] > a[i]) return a[i] + a[i-1] + a[i-2];
        return 0;
    }
};
