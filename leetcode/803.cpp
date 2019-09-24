class DisjointSet{
private:
    int n;
    vector<int> leader;
    vector<int> weight;

public:
    DisjointSet(int size):
        n(size)
    {
        leader = vector<int>(n);
        weight = vector<int>(n);
        for (int i=0;i<n;++i) {
            leader[i] = i;
            weight[i] = 1;
        }
    }

    int find_set(int k){
        if (leader[k] == k) return k;
        leader[k] = find_set(leader[k]);
        weight[k] = weight[leader[k]];
        return leader[k];
    }

    void union_set(int x, int y){
        if (find_set(x) == find_set(y)) return;
        // always attach smaller weight to larger weight
        // make sure the set of x have larger weight
        if (weight[find_set(x)] < weight[find_set(y)]){
            union_set(y,x);
        }
        else{
            weight[find_set(x)] = weight[find_set(x)] + weight[find_set(y)];
            leader[find_set(y)] = find_set(x);
        }
    }

    int count_set(){
        unordered_set<int> label_set;
        for (int i=0;i<n;++i)
            label_set.insert(find_set(i));
        return label_set.size();
    }

    int get_weight(int k){
        return weight[find_set(k)];
    }

    void print_leader(){
        for (int i=0;i<n;++i){
            printf("%d --> %d\n", i, find_set(i));
        }
    }
};

class Solution {
    vector<int> x_diff = {-1, 0, 0, 1};
    vector<int> y_diff = {0, -1, 1, 0};
    int n, m;

    int encode(int x, int y){
        return (x * m + y);
    }

    void decode(int code, int &x, int &y){
        x = code / m;
        y = code % m;
    }

    bool in_board(int x, int y){
        if (x < 0 || x >=n) return false;
        if (y < 0 || y >=m) return false;
        return true;
    }

    void connect(int x, int y, const vector<vector<int>> &grid, DisjointSet &ds){
        for (int k=0; k<4;++k){
            int next_x = x + x_diff[k];
            int next_y = y + y_diff[k];
            if (in_board(next_x, next_y) && grid[next_x][next_y] == 1) 
                ds.union_set(encode(x,y), encode(next_x, next_y));
            }
    }

public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        // init global variables
        n = grid.size();
        m = grid[0].size();
        DisjointSet ds(n*m);
        vector<int> result(hits.size(), -1);

        // get final board
        // if hits[i] remove 0, then result must be 0
        int x, y;
        for (int i=0;i<hits.size();++i){
            x = hits[i][0];
            y = hits[i][1];
            if (grid[x][y] == 0) result[i] = 0;
            else grid[x][y] = 0;
        }

        // init disjoint set
        for(int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                if (grid[i][j] == 1) connect(i,j, grid, ds);
        
        // fixed store fixed partitions
        unordered_set<int> fixed;
        for (int j=0;j<m;++j) 
            if (grid[0][j] == 1) fixed.insert(ds.find_set(encode(0,j)));

        // process hits backward
        for (int i=hits.size()-1; i>=0; --i){
            if (result[i] == 0) continue;
            x = hits[i][0];
            y = hits[i][1];
            int fixed_count = (x==0?1:0);
            unordered_set<int> unfixed_partitions;
            for (int k=0; k<4;++k){
                int next_x = x + x_diff[k];
                int next_y = y + y_diff[k];
                if (in_board(next_x, next_y) && grid[next_x][next_y] == 1) {
                    // try neighbour of x,y
                    int tmp = ds.find_set(encode(next_x, next_y));
                    if (fixed.find(tmp) == fixed.end()) unfixed_partitions.insert(tmp); 
                    else fixed_count += ds.get_weight(tmp);
                }
            }
            // from unfixed_partitions, calculate unfixed_count
            int unfixed_count = 0;
            for (auto x : unfixed_partitions) unfixed_count += ds.get_weight(x);
            if (fixed_count > 0) 
                result[i] = unfixed_count; 
            else 
                result[i] = 0;

            // add x,y back into grid
            grid[x][y] = 1;
            connect(x,y,grid,ds);
            if (fixed_count > 0) fixed.insert(ds.find_set(encode(x,y)));
        }
        return result;
    }
};
