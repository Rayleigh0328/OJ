class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> a;
        for (int i=1; i<=n; ++i)
            if (n % i == 0) a.push_back(i);
        if (a.size() < k) return -1;
        return a[k-1];
    }
};
