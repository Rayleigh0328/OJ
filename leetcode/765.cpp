/*
 * graph theory modeling:
 * vertex v_i corresponding to array index 2*i and 2*i + 1
 * let x is located at v_1
 * let y is the spouse of x and y is located at v_2
 * add an undirected edge (v_1, v_2)
 *
 * for each connected componet of size S, S-1 swap is needed 
 *
 */

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
    vector<int> pos;
    int get_spouse(int x){
        if (x&1) return x - 1;
        else return x + 1;
    }
    int get_pair(int x){
        return pos[x]/2;
    }
public:
    int minSwapsCouples(vector<int>& a) {
        int n = a.size();
        pos = vector<int> (n);
        for (int i=0; i<n; ++i) pos[a[i]] = i;
        DisjointSet ds(n/2);
        int u,v;
        for (int i=0;i<n;++i){
            ds.union_set(get_pair(a[i]), get_pair(get_spouse(a[i])));
        }
        unordered_set<int> processed;
        int ans = 0;
        for (int i=0;i<n/2;++i){
            if (processed.find(ds.find_set(i)) == processed.end()){
                processed.insert(ds.find_set(i));
                ans += ds.get_weight(i) - 1;
            }
        }
        return ans;
    }
};
