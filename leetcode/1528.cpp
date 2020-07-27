class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        const int n = s.size();
        vector<char> tmp(n);
        for (int i=0;i<n;++i)
            tmp[indices[i]] = s[i];
        string result;
        for (auto ch : tmp) result += ch;
        return result;
    }
};
