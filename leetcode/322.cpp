class Solution {
private:
    const int inf = 1000000;
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 0) return -1;
        int *f = new int [amount + 1];
        for (int i=0;i<amount+1;++i)
            f[i] = inf;
        f[0] = 0;
        for (int i = 1;i<=amount;++i)
            for (int j=0;j<coins.size();++j)
                if (i-coins[j]>=0)
                    f[i] = min(f[i], f[i-coins[j]] + 1);
        if (f[amount]==inf) return -1;
        else return f[amount];
    }
};