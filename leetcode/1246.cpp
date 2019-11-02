class Solution {
    static const int MAX_SIZE=102;
    static const int inf=102;
    int f[MAX_SIZE][MAX_SIZE];
    vector<int> a;
    
    int solve(int left, int right){
        if (left == right) return 1;
        if (f[left][right] != inf) return f[left][right];
        
        int result = inf;
        for (int k=left;k<right;++k)
            result = min(result, solve(left, k) + solve(k+1, right));
        if (a[left] == a[right]){
            if (right == left + 1) result = min(result, 1);
            else result = min(result, solve(left+1, right-1));
        } 
        
        return (f[left][right]=result);
    }
    
public:
    int minimumMoves(vector<int>& arr) {
        a = arr;
        int n = a.size();
        for (int i=0;i<MAX_SIZE;++i)
            for (int j=0;j<MAX_SIZE;++j)
                f[i][j] = inf;
        return solve(0,n-1);
    }
};
