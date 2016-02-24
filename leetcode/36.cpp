class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& a) {
        bool ans = true;
        for (int i=0;i<9;++i)
            for (int j=0;j<9;++j)
                if (!(a[i][j] == '.' || ('1'<=a[i][j] && a[i][j]<='9'))) return false;
        
        bool *flag = new bool [200];
        
        //check row
        for (int i=0;i<9;++i)
        {
            for (int t=0;t<200;++t) flag[t] = false;
            for (int j=0;j<9;++j)
                if ('1'<=a[i][j] && a[i][j]<='9')
                    if (flag[a[i][j]]) return false;
                    else flag[a[i][j]] = true;
        }
        
        //check col
        for (int i=0;i<9;++i)
        {
            for (int t=0;t<200;++t) flag[t] = false;
            for (int j=0;j<9;++j)
                if ('1'<=a[j][i] && a[j][i]<='9')
                if (flag[a[j][i]]) return false;
                else flag[a[j][i]] = true;
        }
        
        
        //check 3*3
        for (int i=0;i<9;i+=3)
            for (int j=0;j<9;j+=3)
            {
                for (int t=0;t<200;++t) flag[t] = false;
                for (int p = 0;p<3;++p)
                    for (int q=0;q<3;++q)
                        if ('1'<=a[i+p][j+q] && a[i+p][j+q]<='9')
                        if (flag[a[i+p][j+q]]) return false;
                        else flag[a[i+p][j+q]] = true;
            }
        
        return true;
    }
};
