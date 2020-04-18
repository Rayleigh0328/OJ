class Solution {
    
    const int mode = 1000000007;
    
public:
    int numberOfArrays(string s, int k) {
        
        // vector<int> pos;
        // for (int i=0;i<s.size();++i)
        //     if (s[i] != '0') pos.push_back(-i);
        // reverse(pos.begin(), pos.end());
        
        int len_k = to_string(k).size();
        printf("len_k: %d\n", len_k);
        
        int n = s.size();
        vector<int> f(n+1);
        f[0] = 1;
        string tmp;
        for (int i=1;i<=n;++i){
            for (int j=i-1;j>=0;--j){
                if (i-j > len_k) break;
                tmp = s.substr(j,i-j);
                if (tmp[0]=='0') continue;
                // cout << tmp << endl;
                if (stoll(tmp) > k) break;
                
                f[i] = (f[i] + f[j]) % mode;
            }
        }
        
        return f[n];
    }
};
