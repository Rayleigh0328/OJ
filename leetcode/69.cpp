class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = min(x, (1<<16));
        while (left < right)
        {
            if (left == right - 1)
                if ((long long)right * right > x) return left;
                else return right;
            int mid = (left + right)/2;
            if ((long long)mid * mid <= x) left = mid;
            else right = mid;
        }
        return left;
    }
};