class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& a) {
        
        const int n = a.size();
        const int m = a[0].size();
        
        map<int, multiset<int>> mp;
        for (int i=0; i<n; ++i)
            for (int j=0;j<m;++j)
                mp[i-j].emplace(a[i][j]);
        
        vector<vector<int>> result(n, vector<int>(m));
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j){
                multiset<int> &s = mp[i-j];
                result[i][j] = *s.begin();
                s.erase(s.begin());
            }
        
        return result;
    }
};
