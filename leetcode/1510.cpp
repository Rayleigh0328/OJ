class Solution {
    
    vector<int> f;
    vector<int> a;
public:
    bool winnerSquareGame(int n) {
        f = vector<int>(n+1, false);
        for (int i=1;i*i<=n;++i) a.push_back(i*i);
        
        for (int i=1;i<=n;++i)
            for (int j=0;j<a.size();++j){
                if (a[j] > i) break;
                if (f[i - a[j]] == false) {
                    f[i] = true;
                    break;
                }
            }
        return f[n];
    }
};
