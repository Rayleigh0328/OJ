class Solution {
    typedef vector<long long> RowVectorType;
    typedef vector<RowVectorType> MatrixType;
    const int mode = 1000000007;
    
    MatrixType* matrix_multiply(const MatrixType &a, const MatrixType &b){
        int n = a.size();
        int x = a[0].size();
        int y = b.size();
        int m = b[0].size();
        assert(x == y);
        MatrixType *rp = new MatrixType(n, RowVectorType(m));
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                for (int k=0;k<x;++k)
                    (*rp)[i][j] = ((*rp)[i][j] + a[i][k] * b[k][j]) % mode;
        
        return rp;
    }
    
    MatrixType* matrix_pow(const MatrixType &a, int p){
        assert(a.size() == a[0].size());
        int n = a.size();
        MatrixType tmp = a;
        
        MatrixType *rp = new MatrixType(n, RowVectorType(n,0));
        for (int i=0;i<n;++i) (*rp)[i][i] = 1;
        
        int cur = 1;
        while (cur <= p){
            if ((p & cur) != 0) rp = matrix_multiply(*rp, tmp);
            cur = (cur << 1);
            tmp = *matrix_multiply(tmp, tmp);
        }
        
        return rp;
    }
    
public:
    int checkRecord(int n) {
        MatrixType v{{1,0,0,0,0,0}};
        MatrixType m{
            {1,1,0,1,0,0},
            {1,0,1,1,0,0},
            {1,0,0,1,0,0},
            {0,0,0,1,1,0},
            {0,0,0,1,0,1},
            {0,0,0,1,0,0}
        };
        MatrixType u{{1},{1},{1},{1},{1},{1}};
        MatrixType result = *matrix_multiply(*matrix_multiply(v, *matrix_pow(m,n)), u);
        return result[0][0];
    }
};
