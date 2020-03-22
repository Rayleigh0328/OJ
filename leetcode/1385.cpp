class Solution {
    
    int dist(int x, int y){
        if (x <= y) return y-x;
        else return x - y;
    }
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        set<int> s, ns;
        for (auto x : arr2) s.emplace(x);
        for (auto x : arr2) ns.emplace(-x);
        int result = 0;
        for (auto x : arr1){
            if (s.lower_bound(x) != s.end() && dist(*(s.lower_bound(x)), x) <= d) continue;
            if (ns.lower_bound(-x) != ns.end() && dist(*(ns.lower_bound(-x)), -x) <= d) continue;
            ++result;
        }
        return result;
    }
};
