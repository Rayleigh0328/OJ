class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        if (tri.size() == 0) return 0;
        
        int len = tri.size() + 2;
        int *f = new int [len];
        int *g = new int [len];
        for (int i=0;i<len;++i) f[i] = g[i] = inf;
            
        f[0] = tri[0][0];
        for (int i=1;i<tri.size();++i)
            if (i%2==1)
                solve(f,g,tri[i]);
            else
                solve(g,f,tri[i]);
        int ans;
        if (tri.size()%2 == 1) 
            ans = get_min(f,len);
        else
            ans = get_min(g,len);
        
        delete [] f;
        delete [] g;
        return ans;
    }
    
private:
    const int inf = 1 << 30;
    int solve(int* f, int* g, const vector<int>& line)
    {
        for (int i=0;i<line.size();++i)
            g[i] = line[i] + min( (i==0?inf:f[i-1]), f[i]);
    }
    
    int get_min(int* a, int len)
    {
        int ans = inf;
        for (int i=0;i<len;++i)
            ans = min(ans, a[i]);
        return ans;
    }
};