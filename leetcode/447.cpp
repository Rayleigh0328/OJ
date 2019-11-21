class Solution {
    
    int dist(const vector<int> &p1, const vector<int> &p2){
        return (p2[0]-p1[0])*(p2[0]-p1[0]) + (p2[1]-p1[1])*(p2[1]-p1[1]);
    }
    
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<int, int> dist_cnt;
        int n = points.size();
        int ans = 0;
        for (int i=0;i<n;++i){
            dist_cnt.clear();
            for (int j=0;j<n;++j)
                ++dist_cnt[dist(points[j], points[i])];
            for (auto &e : dist_cnt)
                ans += e.second * (e.second - 1);
        }
            
        return ans;
    }
};
