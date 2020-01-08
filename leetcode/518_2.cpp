class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> f(amount+1, 0);
        f[0] = 1;
        for (auto coin : coins){
            for (int i=0;i+coin<=amount;++i)
                if (f[i] > 0)
                    f[i+coin] += f[i];
        }
        return f[amount];
    }
};
