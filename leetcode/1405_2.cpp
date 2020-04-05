class Solution {
    
    int f[101][101][101][7];
    
    string construct_ans(int x, int y, int z, int s){
        string result = "";
        while (x > 0 || y > 0 || z > 0){
            printf("%d %d %d %d\n", x,y,z,s);
            if (s == 1){
                for (int state = 0; state < 7; ++state)
                    if(state != 1 && state != 2 && x>0)
                        if (f[x][y][z][s] == 1 + f[x-1][y][z][state]) {
                            --x;
                            s = state;
                            result.push_back('a');
                            break;
                        }
            } else if (s == 2){
                --x;
                s = 1;
                result.push_back('a');
            } else if (s == 3){
                for (int state = 0; state < 7; ++state)
                    if(state != 3 && state != 4 && y>0)
                        if (f[x][y][z][s] == 1 + f[x][y-1][z][state]) {
                            --y;
                            s = state;
                            result.push_back('b');
                            break;
                        }
            } else if (s == 4){
                --y;
                s = 3;
                result.push_back('b');
            } else if (s == 5){
                for (int state = 0; state < 7; ++state)
                    if(state != 5 && state != 6 && z>0)
                        if (f[x][y][z][s] == 1 + f[x][y][z-1][state]) {
                            --z;
                            s = state;
                            result.push_back('c');
                            break;
                        }
            } else {
                --z;
                s = 5;
                result.push_back('c');
            }
        }
        
        return result;       
    }
    
public:
    string longestDiverseString(int la, int lb, int lc) {
        
        for (int i=0;i<101;++i)
            for (int j=0;j<101;++j)
                for (int k=0;k<101;++k)
                    for (int x = 0; x<7; ++x){
                            f[i][j][k][x] = -(1<<28);
                            }
        
        f[0][0][0][0] = 0;
        
        // dp
        for (int i=0;i<=la;++i)
            for (int j=0;j<=lb;++j)
                for (int k=0;k<=lc;++k){
                    if (i>0) { f[i][j][k][2] = 1 + f[i-1][j][k][1]; }
                    if (j>0) { f[i][j][k][4] = 1 + f[i][j-1][k][3]; }
                    if (k>0) { f[i][j][k][6] = 1 + f[i][j][k-1][5]; }
                    
                    for (int state = 0; state < 7; ++state)
                        if(state != 1 && state != 2 && i>0)
                            f[i][j][k][1] = max(f[i][j][k][1], 1 + f[i-1][j][k][state]);
                    
                    for (int state = 0; state < 7; ++state)
                        if(state != 3 && state != 4 && j>0)
                            f[i][j][k][3] = max(f[i][j][k][3], 1 + f[i][j-1][k][state]);
                    
                    for (int state = 0; state < 7; ++state)
                        if(state != 5 && state != 6 && k>0)
                            f[i][j][k][5] = max(f[i][j][k][5], 1 + f[i][j][k-1][state]);
                }
    
        int max_length = 0;
        for (int i=0;i<101;++i)
            for (int j=0;j<101;++j)
                for (int k=0;k<101;++k)
                    for (int s=0;s<7;++s)
                        if (f[i][j][k][s] > max_length)
                            max_length = f[i][j][k][s];
        printf("%d\n", max_length);
        // printf("%d\n", f[0][0][2][6]);

        for (int i=0;i<101;++i)
            for (int j=0;j<101;++j)
                for (int k=0;k<101;++k)
                    for (int s=0;s<7;++s)
                        if (f[i][j][k][s] == max_length)
                            return construct_ans(i,j,k,s);
        return "";
    }
};
