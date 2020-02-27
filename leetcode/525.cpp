class Solution {
public:
    int findMaxLength(vector<int>& a) {
        if (a.empty()) return 0;
        const int n = a.size();
        vector<int> s(n,0);
        s[0] = (a[0]==1?1:-1);
        for (int i=1;i<n;++i)
            if (a[i] == 0) s[i]= s[i-1]-1;
            else s[i] = s[i-1] + 1;
        int result = 0;
        map<int, int> mp={{0,-1}};
        for (int i=0;i<n;++i)
            if (mp.find(s[i]) != mp.end()) result = max(result, i - mp[s[i]]);
            else mp[s[i]] = i;
        return result;
    }
};
