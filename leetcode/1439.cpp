class Solution {
    int target;
    vector<vector<int>> a;
    vector<int> requirement;
    
    int count(int limit){
        map<int, int> f,g;
        f[limit] = 1;
        for (int i=0;i<a.size();++i){
            for (int j=0;j<a[i].size();++j){
                for (auto &p : f)
                    if (p.first - a[i][j] >= requirement[i]) g[p.first-a[i][j]] += p.second;
                if (g.size() > target) return target + 1;
            }
            f = g;
            g.clear();
        }
        int result = 0;
        for (auto &p : f)
            result += p.second;
        return result;
    }
    
public:
    int kthSmallest(vector<vector<int>>& input, int k) {
        target = k;
        a = input;
        
        int lb = 0, ub = 1;
        for (auto &v : a) lb += v.front();
        for (auto &v : a) ub += v.back();
        
        requirement = vector<int>(a.size(),0);
        for (int i=a.size()-2;i>=0;--i)
            requirement[i] = requirement[i+1] + a[i+1][0];
        
        int left = lb, right = ub, mid;
        while (left < right){
            if (left + 1 == right) return left;
            if (left + 2 == right)
                if (count(left) < k) return left+1;
                else return left;
            
            mid = left + (right - left) / 2;
            if (count(mid) < k) left = mid + 1;
            else right = mid + 1;
        }
        return 0;
    }
};
