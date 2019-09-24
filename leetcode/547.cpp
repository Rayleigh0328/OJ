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
public:
    int findCircleNum(vector<vector<int>>& m) { 
        int n = m.size();
        if (n == 0) return 0;
        DisjointSet ds(n);
        for (int i=0;i<n;++i)
            for (int j=i + 1;j<n;++j)
                if (m[i][j] == 1) ds.union_set(i,j);
        return ds.count_set();
    }
};
