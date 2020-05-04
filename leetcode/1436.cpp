class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> s;
        for (auto &e : paths) s.emplace(e[0]);
        for (auto &e : paths)
            if (s.find(e[1]) == s.end()) return e[1];
        return "";
    }
};
