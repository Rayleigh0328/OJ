class Solution {
private:
    int n, m;
    queue<int> que;
    
    void enque(int x, int y, vector<vector<char>>& g)
    {
        if (x < 0 || y < 0 || x >= n || y >= m) return;
        if (g[x][y] != 'O') return;
        
        g[x][y] = '#';
        que.push(x*m+y);
    }
    
    void bfs(vector<vector<char>>& g)
    {
        while (!que.empty())
        {
            int tmp = que.front();
            que.pop();
            int x = tmp / m;
            int y = tmp % m;
            enque(x-1,y,g);
            enque(x+1,y,g);
            enque(x,y-1,g);
            enque(x,y+1,g);
        }
    }
    
public:
    void solve(vector<vector<char>>& g) 
    {
        n = g.size();
        if (n == 0) return ;
        m = g[0].size();
        if (m == 0) return ;
        while (!que.empty()) que.pop();
        for (int i=0;i<m;++i) enque(0,i,g);
        for (int i=0;i<m;++i) enque(n-1,i,g);
        for (int i=0;i<n;++i) enque(i,0,g);
        for (int i=0;i<n;++i) enque(i,m-1,g);
        
        bfs(g);
        
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                if (g[i][j] == 'O') g[i][j] = 'X';
        
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                if (g[i][j] == '#') g[i][j] = 'O';
    }
};