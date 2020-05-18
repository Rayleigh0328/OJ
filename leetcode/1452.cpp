class Solution {
    
    bool contains(unordered_set<string> &x, unordered_set<string> &y){
        for (auto e : y){
            if (x.find(e) == x.end()) return false;
        }
        return true;
    }
    
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        const int n = favoriteCompanies.size();
        vector<unordered_set<string>> a(n);
        for (int i=0;i<n; ++i){
            for (auto &s : favoriteCompanies[i])
                a[i].emplace(s);
        }
        
        vector<int> result;
        for (int i=0;i<n;++i){
            bool unique = true;
            for (int j=0;j<n;++j)
                if (i != j){
                    if (contains(a[j], a[i])) {
                        unique = false;
                        break;
                    }
                }
            if (unique) result.push_back(i);
        }
        
        return result;
    }
};
