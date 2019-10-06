class Solution {
public:
    int longestSubsequence(vector<int>& a, int diff) {
        int n = a.size();
        unordered_map<int,int> m;
        int to_find;
        for (int i=0;i<n;++i){
            to_find = a[i] - diff;
            if (m.find(to_find) == m.end()) m.emplace(a[i], 1);
            else m[a[i]] = m[to_find] + 1;
        }
        int ans=0;
        for (auto x : m) ans = max(ans, x.second);
        return ans;
    }
};
