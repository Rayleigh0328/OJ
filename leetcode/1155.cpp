class Solution {
private:
       int  mod = 1000000007;
public:
    int numRollsToTarget(int d, int dice, int target) {
        vector<vector<int>> f(d+1, vector<int>(target+1, 0));
        f[0][0] = 1;
        for (int i=0;i<d;++i){
            for (int j=i;j<=target;++j)
                if (f[i][j] == 0) {
                    break;
                }
                else {
                    for (int x = 1; x <= dice && j+x <= target; ++x)
                        f[i+1][j+x] = (f[i+1][j+x] + f[i][j]) % mod;
                }
        }
        /*
        for (int i=0; i<=d;++i){
            for (int j=0; j<=target; ++j)
                cout << f[i][j] << " ";
            cout << endl;
        }
        */
        return f[d][target];
    }
};
