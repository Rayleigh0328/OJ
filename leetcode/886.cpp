class Solution {
    vector<vector<int>> edge;
    vector<int> color;
    bool result;
    
    void dfs(int k, int c){
        if (color[k] == -1){
            color[k] = c;
            for (int u : edge[k])
                dfs(u, 1-c);
        }
        else{
            if (color[k] != c) result = false;
        }
    }
    
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        edge=vector<vector<int>>(n);
        for (auto &e : dislikes){
            edge[e[0]-1].push_back(e[1]-1);
            edge[e[1]-1].push_back(e[0]-1);
        }
        color = vector<int>(n, -1);
        result = true;
        for (int i=0;i<n;++i)
            if (color[i] == -1)
                dfs(i, 0);
        return result;
    }
};
