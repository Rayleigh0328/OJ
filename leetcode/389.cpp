class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> count_s;
        unordered_map<char, int> count_t;
        for (char ch : s) ++count_s[ch];
        for (char ch : t) ++count_t[ch];
        for (auto & e : count_t)
            if (count_s[e.first] < e.second) return e.first;
        return 0;
    }
};
