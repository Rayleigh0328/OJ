class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> mp;
        for (char ch='a';ch<='z';++ch) mp[ch] = 32;
        mp['a'] = 1;
        mp['e'] = 2;
        mp['i'] = 4;
        mp['o'] = 8;
        mp['u'] = 16;
        int mask = 31;
        
        int result = 0;
        int state = 0;
        unordered_map<int, int> prev;
        prev[0]=-1;
        for (int i=0;i<s.size();++i){
            state = (state ^ mp[s[i]]) & mask;
            if (prev.find(state) == prev.end()){
                prev[state] = i;
            }
            else {
                result = max(result, i - prev[state]);
            }
        }
        return result;
    }
};
