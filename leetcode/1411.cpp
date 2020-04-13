class Solution {
    
    const int max_state = 27;
    const int mode = 1000000007;
    
    typedef int State;
    
    vector<int> convert_to_vec(State s){
        vector<int> result(3);
        for (int i=0;i<3;++i){
            result[i] = s % 3;
            s /= 3;
        }
        return result;
    }
    
    bool check(State s){
        vector<int> v = convert_to_vec(s);
        return (v[0] != v[1] && v[1] != v[2]);
    }
    
    bool check(State s1, State s2){
        if (!check(s1) || !check(s2)) return false;
        vector<int> u = convert_to_vec(s1);
        vector<int> v = convert_to_vec(s2);
        return (u[0] != v[0] && u[1] != v[1] && u[2] != v[2]);
    }
    
public:
    int numOfWays(int n) {
        vector<vector<int>> f(n, vector<int>(max_state, 0));
        
        vector<vector<int>> good(max_state, vector<int>(max_state, 0));
        for (int i=0;i<max_state;++i)
            for (int j=0;j<max_state;++j)
                if (check(i,j)) good[i][j] = 1;
        
        for (int s=0;s<max_state;++s){
            if (check(s)) f[0][s] = 1;
        }
        for (int i=1;i<n;++i)
            for (int j=0;j<max_state;++j)
                for (int prev=0;prev<max_state;++prev)
                    if (good[prev][j] == 1) 
                        f[i][j] = (f[i][j] + f[i-1][prev]) % mode;
        
        int result = 0;
        for (int j=0;j<max_state;++j)
            result = (result + f[n-1][j]) % mode;
        return result;
    }
};
