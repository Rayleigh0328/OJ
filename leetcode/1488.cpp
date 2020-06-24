class Solution {
public:
    vector<int> avoidFlood(vector<int>& a) {
        const int n = a.size();
        // find next appearance
        vector<int> f(n, -1);
        unordered_map<int, int> next_pos;
        for (int i=n-1;i>=0;--i) {
            if (a[i] == 0) continue;
            if (next_pos.find(a[i]) != next_pos.end()) f[i] = next_pos[a[i]];
            next_pos[a[i]] = i;
        }
        
        // for (auto x : f) cout << x << " "; cout << endl; 
        
        vector<int> result(n, 1);
        map<int, int> pos;
        set<int> value_set;
        for (int i=0;i<n;++i){
            if (a[i] == 0) {
                if (pos.empty()){
                    result[i] = 1;
                }
                else {
                    result[i] = pos.begin()->second;
                    value_set.erase(result[i]);
                    pos.erase(pos.begin());
                }
            }
            else {
                result[i] = -1;
                if (value_set.find(a[i]) != value_set.end()) return {};
                value_set.emplace(a[i]);
                if (f[i] != -1) pos[f[i]] = a[i];
            }
        }
        return result;
    }
};
