class Solution {
    const double INF = 1e10;
    const double eps = 1e-8;

    double my_abs(double x){
        if (x < 0) return -x;
        return x;
    }

    bool equal(double x, double y){
        return my_abs((double)x-y) < eps;
    }


public: 
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int tot_eqs = values.size();
        int size = 0;
        // map string to graph node
        unordered_map<string,int> map_st_to_node;
        for(auto eq : equations){
            for (int i=0;i<=1;++i)
                if (map_st_to_node.find(eq[i]) == map_st_to_node.end())
                    map_st_to_node.emplace(eq[i], size++);
        }

        int u,v;
        double w;
        vector<vector<double>> g(size, vector<double>(size, INF));
        for (int i=0;i<tot_eqs;++i){ 
            u = map_st_to_node[equations[i][0]];
            v = map_st_to_node[equations[i][1]];
            w = values[i];
            g[u][u] = 1;
            g[v][v] = 1;
            g[u][v] = w;
            if (!equal(w, 0)) g[v][u] = 1.0/w;
        }

        for (int k=0;k<size;++k)
            for (int i=0;i<size;++i)
                for (int j=0;j<size;++j)
                    if (i != j && j != k && i != k)
                        if (!equal(g[i][k], INF) && !equal(g[k][j], INF))
                            g[i][j] = g[i][k] * g[k][j];



        vector<double> ans;
        for (auto query : queries){
            if (map_st_to_node.find(query[0]) == map_st_to_node.end() || map_st_to_node.find(query[1]) == map_st_to_node.end()){
                ans.push_back(-1);
                continue;
            }
            u = map_st_to_node[query[0]];
            v = map_st_to_node[query[1]];
            double tmp = g[u][v];
            if (tmp >= INF-eps) tmp = -1;
            ans.push_back(tmp);
        }
        return ans;         
    }
};
