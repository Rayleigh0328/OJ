class Solution {
public:
    int maxProfit(vector<int>& v, int t) {
       vector<int> f(v.size());
       vector<int> g(v.size());
       f[0] = -v[0];
       g[0] = 0;
       for (int i=1;i<v.size();++i){ 
           f[i] = max(f[i-1], g[i-1] - v[i]); 
           g[i] = max(g[i-1], f[i-1] + v[i] - t);
       }
//       for (auto x : f) cout<< x << " "; cout << endl;
//       for (auto x : g) cout<< x << " "; cout << endl;
       return max(f[v.size()-1], g[v.size()-1]);
    }
};
