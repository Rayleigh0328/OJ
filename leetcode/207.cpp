class Solution {
public:
    bool canFinish(int n, vector<pair<int, int>>& pre) 
    {
        bool ** g = new bool * [n];
        for (int i=0; i<n; ++i)
            g[i] = new bool [n];
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                g[i][j] = false;
                
        int * out_deg = new int [n];
        for (int i=0;i<n;++i) out_deg[i] = 0;
        
        for (int i=0;i<pre.size();++i)
            if (!g[pre[i].first][pre[i].second])
            {
                g[pre[i].first][pre[i].second] = true;
                ++out_deg[pre[i].first];
            }
        
        int * que  = new int [n + 2];
        int p1=0, p2=0;
        
        for (int i=0;i<n;++i)
            if (out_deg[i] == 0)
                que[p2++] = i;
        
        while (p1 < p2)
        {
            for (int i=0;i<n;++i)
                if (g[i][que[p1]] == 1)
                    if (--out_deg[i] == 0) que[p2++] = i;
            ++p1;
        }
        
        return p1 == n;
    }
};