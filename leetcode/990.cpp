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
    int relabel(char ch){
        return (int) ch - 'a';
    }
public:
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds(relabel('z') + 1);
        for (string eq : equations){
            if (eq[1] == '=') ds.union_set(relabel(eq[0]), relabel(eq[3]));
        }
        for (string eq : equations){
            if (eq[1] == '!' && ds.find_set(relabel(eq[0])) == ds.find_set(relabel(eq[3]))) return false;
        }
        return true;
    }
};
