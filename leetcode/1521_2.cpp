class Solution {
    
    const int inf = (1<<30);
    
    void update(unordered_set<int> &f, unordered_set<int> &g, int k, int target, int &result){
        g.clear();
        for (auto x : f)
            g.emplace(x & k);
        g.emplace(k);
        for (auto x : g)
            result = min(result, abs(x - target));
    }
    
public:
    int closestToTarget(vector<int>& a, int target) {
        int result = inf;
        unordered_set<int> f, g;
        for (int i=0;i<a.size();++i){
            if (i & 1) update(g,f,a[i],target, result);
            else update(f,g,a[i],target, result);
        }
        return result;
    }
};
