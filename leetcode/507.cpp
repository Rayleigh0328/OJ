class Solution {
    const double eps = 1e-8;
public:
    bool checkPerfectNumber(int x) {
        if (x == 1) return false;
        int sum = 1;
        for (int i=2; i<=sqrt(x) + eps; ++i)
            if (x % i == 0) sum += i + x/i;
        return x == sum;
    }
};
