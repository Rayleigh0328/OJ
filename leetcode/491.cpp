struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};

class Solution {
    
    vector<int> a;
    int n;
    
    vector<int> get_sequence(int k){
        vector<int> result;
        for (int i=0;i<n;++i)
            if (k & (1<<i))
                result.push_back(a[i]);
        return result;
    }
    
    bool check(const vector<int> &v){
        if (v.size() < 2) return false;
        for (int i=1;i<v.size();++i)
            if (v[i] < v[i-1]) return false;
        return true;
    }
    
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        a = nums;
        unordered_set<vector<int>, VectorHash> result;
        for (int i=1;i<(1<<n);++i){
            vector<int> candidate = get_sequence(i);
            if (check(candidate)) result.emplace(candidate);
        }
        vector<vector<int>> ans;
        for (auto x : result)
            ans.push_back(x);
        return ans;
    }
};
