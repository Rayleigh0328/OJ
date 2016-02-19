class Solution {
public:
    int maxProfit(vector<int>& p) {
        f = new int* [p.size()];
        for (int i=0;i<p.size();++i)
            f[i] = new int [2];
        
        for (int i=0;i<p.size();++i)
        {
            f[i][1] = max(get_f(i-1,0), get_f(i-1,1));
            f[i][0] = 0;
            for (int j=0;j<i;++j)
                f[i][0] = max(f[i][0], get_f(j-1,1) + p[i]-p[j]);
        }
        
        //for (int i=0;i<p.size();++i) cout << f[i][0] << " ";
        //cout << endl;
        //for (int i=0;i<p.size();++i) cout << f[i][1] << " ";
        //cout << endl;
        
        int ans = 0;
        for (int i=0;i<p.size();++i)
            ans = max(ans, f[i][0]);
        return ans;
    }
private:    
    int** f;
    int get_f(int x, int y)
    {
        if (x < 0) return 0;
        return f[x][y];
    }
};