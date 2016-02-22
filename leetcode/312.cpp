class Solution {
public:
    int maxCoins(vector<int>& nums) 
    {
        int n = nums.size()+2;
        int* p = new int [n];
        p[0] = p[n-1] = 1;
        for (int i=1;i<n-1;++i)
            p[i] = nums[i-1];
        
        int** f = new int* [n];
        for (int i=0;i<n;++i)
            f[i] = new int [n];
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                f[i][j] = 0;
        
        for (int t=0; t<n;++t)
            for (int i=1;i<n-1;++i)
                if (i+t < n-1)
                    for (int j=i;j<=i+t;++j)
                        f[i][i+t] = max(f[i][i+t], (i<=j-1?f[i][j-1]:0) + (j+1<=i+t?f[j+1][i+t]:0) + p[j]*p[i-1]*p[i+t+1]);
        /*
        for (int i=0;i<n;++i)
        {
            for (int j=0;j<n;++j)
                cout << "\t" << f[i][j];
            cout << endl;
        }
        */
        return f[1][n-2];
    }
};