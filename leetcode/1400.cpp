class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) return false;
        unordered_map<char,int> count;
        for (int i=0;i<s.size();++i){
            char ch = s[i];
            ++count[ch];
        }
        int odd_count = 0;
        for (auto &e : count)
            if (e.second & 1) ++odd_count;
        if (odd_count > k) return false;
        return true;
    }
};
