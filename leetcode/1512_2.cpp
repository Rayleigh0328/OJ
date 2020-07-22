class Solution {
public:
    int numIdenticalPairs(vector<int>& a) {
        unordered_map<int,int> count;
        for (auto x : a) ++count[x];
        int result = 0;
        for (auto &e : count)
            result += e.second * (e.second - 1) / 2;
        return result;
    }
};
