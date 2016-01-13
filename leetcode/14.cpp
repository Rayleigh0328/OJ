class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string ans = "";
        int pos = 0;
        while (true)
        {
            bool same = true;
            for (int i=0;i<strs.size();++i)
                if (pos >= strs[i].size() || strs[i][pos]!=strs[0][pos])
                {
                    same = false;
                    break;
                }
            if (same) ans += strs[0][pos++];
            else break;
        }
        return ans;
    }
};