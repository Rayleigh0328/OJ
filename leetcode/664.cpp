class Solution {
    const int inf = (1<<29);
    
    vector<int> exp;
    vector<vector<vector<int>>> f;
    int n;
    
    int solve(int left, int right, int color){
        if (left > right) return 0;
        if (f[left][right][color] != -1) return f[left][right][color];
        
        int result = inf;
        if (color == exp[left]){
            result = solve(left+1,right,color);
        }
        else {
            for (int i=left;i<=right;++i)
                result = min(result, 1 + solve(left,i,exp[left]) + solve(i+1,right,color));
        }
        // printf("(%d %d %d) ==> %d\n", left, right, color, result);
        return (f[left][right][color] = result);
    }
    
public:
    int strangePrinter(string s) {
        for (int i=0;i<s.length();++i)
            exp.push_back(s[i]-'a');
        n = s.length();
        f = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(27,-1)));
        return solve(0,n-1,26);
    }
};
