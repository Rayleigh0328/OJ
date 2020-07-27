
class Solution {
    
    static const int max_size = 102;
    static const int max_suffix_len = 11;
    const int inf = (1<<30);
    
    int f[max_size][max_size][max_suffix_len];
    int run_length[max_size];
    
    bool is_one_char_string(const string &s){
        for (int i=1;i<s.size();++i)
            if  (s[i] != s[i-1]) return false;
        return true;
    }
    
public:
    int getLengthOfOptimalCompression(string s, int del) {
        
        // init run_length
        run_length[0] = 0;
        run_length[1] = 1;
        for (int i=2;i<10;++i) run_length[i] = 2;
        for (int i=10;i<100;++i) run_length[i] = 3;
        run_length[100] = 4;

        s = '^' + s;
        const int n = s.size();
        // handle special case
        if (is_one_char_string(s)) return run_length[n-1-del];
        
        // init
        for (int i=0;i<max_size;++i)
            for (int j=0;j<max_size;++j)
                for (int k=0;k<max_suffix_len;++k)
                    f[i][j][k] = inf;
        
        // boundary
        f[0][0][1] = 0;
        
        for (int i=1;i<n;++i)
            for (int d=0;d<=del;++d){
                for (int j=i-1;j>=0;--j){
                    if (i-j-1>d) break;
                    // d* = d -i + j + 1
                    if (s[i] != s[j]){
                        for (int k=1;k<max_suffix_len;++k) f[i][d][1] = min(f[i][d][1], f[j][d-i+j+1][k] + 1); 
                    }
                    else {
                        for (int k=1;k<max_suffix_len;++k) f[i][d][min(k+1,10)] = min(f[i][d][min(k+1,10)], f[j][d-i+j+1][k] - run_length[k] + run_length[k+1]);
                    }
                }
            }
        
        int result = inf;
        for (int i=0;i<n;++i)
            for (int d=0;d<=del;++d)
                for (int k=0;k<max_suffix_len;++k)
                    if (d + n - i - 1 <= del) result = min(result, f[i][d][k]);
        return result;
    }
};


