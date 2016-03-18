class Solution {
public:
    vector<int> findOrder(int n, vector<pair<int, int>>& pre) 
    {
        vector<int>* g = new vector<int> [n];
        for (int i=0;i<n;++i) g[i].clear();
        
        int* degree = new int [n];
        for (int i=0;i<n;degree[i++] = 0);
        
        for (int i=0;i<pre.size();++i)
        {
            g[pre[i].second].push_back(pre[i].first);
            ++degree[pre[i].first];
        }
        
        queue<int> que;
        while (!que.empty()) que.pop();
        
        for (int i=0;i<n;++i)
            if (degree[i] == 0) que.push(i);
        
        vector<int> ans;
        ans.clear();
        while (!que.empty())
        {
            int cur = que.front();
            que.pop();
            ans.push_back(cur);
            for (int i=0;i<g[cur].size();++i)
                if (--degree[g[cur][i]] == 0) que.push(g[cur][i]);
        }
        
        if (ans.size() == n) return ans;
        else return vector<int>();
    }
};