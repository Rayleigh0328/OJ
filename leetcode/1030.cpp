class Solution {
    typedef pair<int, int> my_type;
    
    static bool cmp(const my_type &x, const my_type &y){
        return x.second < y.second;
    }
    
public:
    vector<vector<int>> allCellsDistOrder(int n, int m, int r0, int c0) {
        vector<my_type> a;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                a.push_back(my_type(i*m+j, abs(i-r0) + abs(j-c0)));
        sort(a.begin(), a.end(), cmp);
        vector<vector<int>> ans;
        for (int i=0;i<a.size();++i){
            vector<int> row{a[i].first / m, a[i].first % m};
            ans.push_back(row);
        }
        return ans;
    }
};
