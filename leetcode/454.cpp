class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        int n = a.size();
        unordered_map<int, int> ab_count;
        unordered_map<int, int> cd_count;
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                ++ab_count[a[i] + b[j]];
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                ++cd_count[c[i] + d[j]];
        int ans = 0;
        for (auto &e : ab_count){
            if (cd_count.find(-e.first) != cd_count.end())
                ans += e.second * cd_count[-e.first];
        }
        return ans;
    }
};
