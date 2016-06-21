class Solution {
public:
    int countNumbersWithUniqueDigits(int n) 
    {
        if (n > 10) return 0;
        if (n == 0) return 1;
        int a[10];
        a[0] = 10;
        a[1] = 81;
        for (int i=8; i>=1; --i)
            a[10-i] = a[10-i-1] * i;
        int ans = 0;
        for (int i=0;i<n;++i)
            ans += a[i];
        return ans;
    }
};