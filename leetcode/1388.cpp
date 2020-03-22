class Solution {
    
    int solve(vector<int> &a, int target){
        vector<vector<int>> f(a.size(), vector<int>(target+1,-1));
        for (int i=0;i<a.size();++i) f[i][0] = 0;
        f[0][1] = a[0]; f[1][1] = max(a[0],a[1]);
        for (int i=2; i<a.size();++i)
            for (int j=1;j<=target;++j)
                f[i][j] = max(f[i-1][j], f[i-2][j-1] + a[i]);
        return f[a.size()-1][target];
    }
    
public:
    int maxSizeSlices(vector<int>& slices) {
        vector<int> a(slices);
        a.pop_back();
        int result = solve(a, slices.size()/3);
        a.push_back(slices.back());
        a.erase(a.begin());
        result = max(result, solve(a, slices.size()/3));
        return result;
    }
};
