// rotation matrix 
class Solution {
    
    void rotate(vector<vector<int>>& a, int i, int j){
        int m = a.size() - 1;
        int tmp = a[m-j][i];
        a[m-j][i] = a[m-i][m-j];
        a[m-i][m-j] = a[j][m-i];
        a[j][m-i] = a[i][j];
        a[i][j] = tmp;
    }
    
public:
    void rotate(vector<vector<int>>& a) {
        // (i,j) --> (j,n-1-i) --> (n-1-i, n-1-j) --> (n-1-j, i)
        int n = a.size();
        if (n & 1){
            for (int i=0;i<(n-1)/2;++i)
                for (int j=0;j<(n+1)/2;++j)
                    rotate(a,i,j);
        }
        else{
            for (int i=0;i<n/2;++i)
                for (int j=0;j<n/2;++j)
                    rotate(a,i,j);
        }
    }
};
