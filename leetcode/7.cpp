// Pay attention to the over 32-bit limit case

class Solution {
public:
    int reverse(int x) {
        long long tmp = (x<0?-x:x);
        long long ans = 0;
        while (tmp != 0ll)
        {
            ans = ans * 10ll + tmp % 10ll;
            tmp /=10;
        }
        if (x < 0) ans = -ans;
        if (ans > INT_MAX || ans < -INT_MAX) return 0;
        else return ans;
    }
};