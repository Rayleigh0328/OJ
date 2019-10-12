#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

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

#endif

struct car{
    int number;
    double arrive_time;
    int start_dist;
    
    car(int n, double at, int sd):
        number(n),
        arrive_time(at),
        start_dist(sd)
    {}
};

const int eps = 1e-8;

bool cmp(const car &x, const car &y){
    if (x.arrive_time > y.arrive_time - eps) return true;
    if (x.arrive_time < y.arrive_time + eps) return false;
    return x.start_dist < y.start_dist;
}

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // for two car x, y to form a fleet
        // say speed(x) >= speed(y)
        // pos(x) must be <= pos(y)
        // and for arrival time
        // (target - pos(x))/speed(x) <= (target-pos(y))/speed(y)
        
        // sort by arrival time, inc
        // for each car i, if car j arrive earlier than i but start dist is larger than i
        // then they form a pack
        // maintain a max heap for start dist use disjoint set
        
        int n = position.size();
        vector<car> a;
        for (int i=0;i<n;++i)
            a.push_back(car(i, (0.0 + target-position[i])/speed[i], target-position[i]));
        sort(a.begin(), a.end(), cmp);
        // for (auto x : a) cout << x.number << " "; cout << endl;
        // for (auto x : a) cout << x.arrive_time << " "; cout << endl;
        // for (auto x : a) cout << x.start_dist << " "; cout << endl;
        DisjointSet ds(n);
        int min_pos = 0;
        for (int i=1;i<n;++i){
            if (a[i].start_dist >= a[min_pos].start_dist)
                ds.union_set(a[i].number, a[min_pos].number);
            else 
                min_pos = i;
        }
        return ds.count_set();
    }
};
