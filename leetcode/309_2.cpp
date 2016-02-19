class Solution {
public:
    int maxProfit(vector<int>& p) {
        
        if (p.size() == 0) return 0;
        
        int* buy = new int [p.size()];
        int* hold = new int [p.size()];
        int* rest = new int [p.size()];
        int* sell = new int [p.size()];
        
        buy[0] = -p[0];
        hold[0] = - max_int;
        rest[0] = 0;
        sell[0] = - max_int;
        
        for (int i=1;i<p.size();++i)
        {
            buy[i] = rest[i-1] - p[i];
            hold[i] = max(hold[i-1], buy[i-1]);
            rest[i] = max(rest[i-1], sell[i-1]);
            sell[i] = max(buy[i-1], hold[i-1]) + p[i];
        }
        
        int ans = max(rest[p.size()-1], sell[p.size()-1]);
        return ans;
    } 
private:
    const int max_int = 1<<30;
};