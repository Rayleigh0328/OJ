class Solution {
public:
    int minSteps(string s, string t) {
        multiset<char> ms;
        for (int i=0;i<t.size();++i)
            ms.emplace(t[i]);
        int result = 0;
        for (int i=0;i<s.size();++i){
            if (ms.find(s[i]) != ms.end()) ms.erase(ms.find(s[i]));
            else ++result;
        }
        return result;
    }
};
