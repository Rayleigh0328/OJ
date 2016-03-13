class Solution {
private:
    string solve(string s)
    {
        string ans="";
        while (!s.empty())
        {
            int pos;
            for (pos=1;pos<s.size();++pos)
                if (s[pos] != s[pos-1]) break;
            ans += to_string(pos) + s[0];
            s = s.substr(pos);
        }
        return ans;
    }

public:
    string countAndSay(int n) {
        string cur="1";
        for (int i=0;i<n-1;++i)
            cur = solve(cur);
        return cur;
    }
};