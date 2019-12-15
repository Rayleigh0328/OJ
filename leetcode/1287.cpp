class Solution {
public:
    int findSpecialInteger(vector<int>& a) {
        unordered_map<int, int> count;
        for (auto x : a) ++count[x];
        for (auto e : count)
            if (e.second > a.size() / 4) 
                return e.first;
        return -1;
    }
};
