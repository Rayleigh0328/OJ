class Solution {
public:
    bool checkIfExist(vector<int>& a) {
        unordered_map<int, int> mp;
        for (auto x : a) ++mp[x];
        if (mp[0] >= 2) return true;
        for (auto x : a)
            if (x != 0 && mp.find(2*x) != mp.end()) return true;
        return false;
    }
};
