class Solution {
    const int inf = (1<<29);
    
    int n;
    vector<vector<int>> f;
    
    int solve(vector<int>&a, int left, int right){
        if (f[left][right] != -1) return f[left][right];
        if (left >= right-1) return 0;
        int result = inf;
        
        for (int i=left+1;i<right;++i)
            result = min(result, solve(a,left, i) + solve(a,i,right) + a[left] * a[right] * a[i]);
        
        return (f[left][right] = result);
    }
    
public:
    int minScoreTriangulation(vector<int>& a) {
        n = a.size();
        f = vector<vector<int>> (n, vector<int>(n,-1));
        return solve(a,0,n-1);
    }
};
