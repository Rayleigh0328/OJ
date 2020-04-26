class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& a) {
        vector<int> result;
        map<int, vector<int>> mp;
        for (int i=0;i<a.size();++i)
            for (int j=0;j<a[i].size();++j)
                mp[i+j].push_back(a[i][j]);
        for (auto &e : mp){
            vector<int> &v = e.second;
            int sz = v.size();
            for (int j=sz-1; j>=0; --j)
                result.push_back(v[j]);
        }
        return result;
    }
};
