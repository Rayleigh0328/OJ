class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        vector<double> f(n+1);
        f[1] = 1;
        for (int i=2;i<=n;++i)
            f[i] = 1.0/i + f[i-1] * (i-2) / i;
        return f[n];
    }
};
