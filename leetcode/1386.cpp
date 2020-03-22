class Solution {
    
    bool mid(const unordered_set<int> &a){
        for (int i=4;i<=7;++i)
            if (a.find(i) != a.end()) return false;
        return true;
    }
    
    bool left(const unordered_set<int> &a){
        for (int i=2;i<=5;++i)
            if (a.find(i) != a.end()) return false;
        return true;
    }
    
    bool right(const unordered_set<int> &a){
        for (int i=6;i<=9;++i)
            if (a.find(i) != a.end()) return false;
        return true;
    }
    
    int solve(const unordered_set<int> &a){
        if (left(a) && right(a)) return 2;
        if (left(a) || right(a) || mid(a)) return 1;
        return 0;
    }
    
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp;
        for (auto &v : reservedSeats)
            mp[v[0]-1].emplace(v[1]);
        int result = 0;
        for (auto &e : mp)
            result += solve(e.second);
        result += 2 * (n - mp.size());
        return result;
    }
};
