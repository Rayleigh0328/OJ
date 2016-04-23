class Solution {
private:
    int pow(int k)
    {
        int ans = 1;
        for (int i=0;i<k;++i)
            ans *= 3;
        return ans;
    }
public:
    int integerBreak(int n) 
    {
        if (n == 2) return 1;
        if (n == 3) return 2;
        
        if (n % 3 == 1) 
            return pow((n-1)/3 - 1) * 2 * 2;
        else if (n % 3 == 2)
            return pow(n/3)*2;
        else
            return pow(n/3);
    }
};