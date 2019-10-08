class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        if (n == 0) return 0;
        
        int *busy = new int [n];
        int *idle = new int [n];
        
        busy[0] = -p[0];
        idle[0] = 0;
        
        for (int i=1;i<n;++i) {
            busy[i] = max(busy[i-1], idle[i-1] - p[i]);
            idle[i] = max(idle[i-1], busy[i-1] + p[i]);
        }
        
        return max(busy[n-1], idle[n-1]);
    }
};
