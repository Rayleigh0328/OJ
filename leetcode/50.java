class Solution {
    double eps = 1e-8;
    public double myPow(double x, int n) {
        // x^0 = 1
        if (n == 0) return 1;
        // 0^x = 0
        if (Math.abs(x) < eps) return 0;

        // x ^ -n = (1/x)^n
        if (n < 0){
            x = 1/x;
            n = -n;
        }

        // doubling
        double tmp = x;
        double ans = 1.0;
        for (int i=0; i<32;++i){
            if ((n & (1<<i)) != 0) ans *= tmp;
            tmp = tmp * tmp;
        }
        return ans;
    }
}
