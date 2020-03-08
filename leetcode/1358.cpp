class Solution {
    const int inf = (1<<25);
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> last_pos;
        int result = 0;
        for (int i=0;i<s.size();++i){
            last_pos[s[i]] = i;
            int pos = inf;
            for (auto e : last_pos)
                pos = min(pos, e.second);
            if (last_pos.size() == 3) 
                result += pos + 1;
        }
        return result;
    }
};
