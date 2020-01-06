class Solution {
    
    bool check(const string& s, int len, int max_letter){
        if (s.size() != len) return false;
        unordered_set<char> char_set;
        for (int i=0;i<s.size();++i)
            char_set.emplace(s[i]);
        return (char_set.size() <= max_letter);
    }
    
    int solve(const string &s, int len, int max_letter){
        unordered_map<string, int> sub_array_count;
        for (int i=0;i<s.size();++i)
            ++sub_array_count[s.substr(i,len)];
        int result = 0;
        for (auto &e : sub_array_count){
            if (check(e.first, len, max_letter)) result = max(result, e.second);
        }
        return result;
    }
    
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int result = 0;
        for (int len = minSize; len <= maxSize; ++len){
            result = max(result, solve(s,len,maxLetters));
            if (result > 0) return result;
        }
        return result;
    }
};
