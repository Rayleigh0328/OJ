class Solution {
    public int divide(int dividend, int divisor) {

        if (dividend == 0) return 0;
        if (dividend == -2147483648 && divisor == -1) return 2147483647;
        if (divisor == 1) return dividend;
        if (divisor == -1) return -dividend;
        //  x / y = z + r

        long x = dividend;
        long y = divisor;
        boolean isNegative;
        if (x < 0 && y< 0) isNegative = false;
        else if (x> 0 && y> 0) isNegative = false;
        else isNegative = true;
        x = Math.abs(x);
        y = Math.abs(y);

        long ans = 0;
        int i=0;
        while (x >= y) {
            while ((y << i) <= x) ++i;
            x -= (y << (i-1));
            ans += (1 << (i-1));
            i=0;
        }
        if (isNegative) return 0 - Long.valueOf(ans).intValue();
        else return Long.valueOf(ans).intValue();
    }
}
