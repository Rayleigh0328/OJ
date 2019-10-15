class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // indegree is n
        // outdegree is 0
        
        vector<int> in(n, 0);
        vector<int> out(n,0);
        int u,v;
        for (auto e : trust){
            u = e[0] - 1;
            v = e[1] - 1;
            ++in[v];
            ++out[u];
        }
        
        for (int i=0;i<n;++i)
            if (in[i] == n-1 && out[i] == 0) return i+1;
        return -1;
    }
};
