class Solution {
    static const int MAXSIZE = 1005;
    long long mode = 1000000007;
    long long f[MAXSIZE];
    
    long long solve(int n){
        if (n == 0) return 1;
        if (n & 1) return 0;
        if (f[n] != -1) return f[n];
        
        long long result = 0;
        for (int i=1;i<n;++i)
            result = (result + solve(i-1) * solve(n-i-1)) % mode;
        return (f[n] = result);
    }
    
public:
    int numberOfWays(int num_people) {
        for (int i=0;i<MAXSIZE;++i) f[i] = -1;
        return static_cast<int>(solve(num_people));
    }
};
