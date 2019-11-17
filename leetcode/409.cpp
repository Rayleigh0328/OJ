class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        for (char ch : s) ++count[ch];
        int ans = 0;
        bool has_odd = false;
        for (auto &e : count){
            if (e.second & 1) has_odd = true;
            ans += e.second - (e.second & 1);
        }
            
        return (has_odd?ans+1:ans);
    }
};
