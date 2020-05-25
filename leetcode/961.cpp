class Solution {
public:
    int repeatedNTimes(vector<int>& a) {
        const int n = a.size();
        unordered_map<int,int> count;
        for (auto x : a) ++count[x];
        for (auto &e : count)
            if (e.second == n/2) return e.first;
        return -1;
    }
};
