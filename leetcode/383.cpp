class Solution {
public:
    bool canConstruct(string x, string y) {
        unordered_map<char,int> count_x;
        unordered_map<char, int> count_y;
        for (char ch : x) ++count_x[ch];
        for (char ch : y) ++count_y[ch];
        for (auto &e : count_x)
            if (e.second > count_y[e.first]) return false;
        return true;
    }
};
