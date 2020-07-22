class Solution {
    
    const int inf = (1<<28);
    
    int n,m;
    vector<vector<int>> span;
    
    int arith(int k){
        return (1 + k) * k / 2; 
    }
    
public:
    int numSubmat(vector<vector<int>>& mat) {
        n = mat.size() + 2;
        m = mat[0].size() + 2;
        
        // wrap 0s around mat to get a new matrix
        vector<vector<int>> a(n, vector<int>(m,0));
        for (int i=0;i<mat.size();++i)
            for (int j=0;j<mat[0].size();++j)
                a[i+1][j+1] = mat[i][j];
        
        // span[i][j] is how many 1s on the top of (i,j)
        span = vector<vector<int>> (n, vector<int>(m,0));
             
        for (int i=1;i<n;++i){
            for (int j=0;j<m;++j)
                span[i][j] = (a[i][j] == 0 ? 0 : 1+span[i-1][j]);
        }
            
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                printf("%d ", span[i][j]);
            }
            printf("\n");
        }
        
        int result = 0;
        for (int i=0;i<n;++i){
            vector<pair<int,int>> st;
            for (int j=0;j<m;++j){
                pair<int,int> cur(span[i][j],j);
                while (!st.empty() && span[i][j] <= st.back().first){
                    result += st.back().first * 
                }
            }
        }
        return result;
    }
};
