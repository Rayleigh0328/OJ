class Solution {
    const int max_size = 5002;
    
    vector<int> cost;
    
    string construct_ans(vector<vector<int>>&f, int len, int target){
        if (len == 0) return "";
        return to_string(f[len][target]) + construct_ans(f, len-1, target-cost[f[len][target]]);
    }
    
public:
    string largestNumber(vector<int>& c, int target) {
        
        cost.push_back(-1);
        for (auto x : c) cost.push_back(x);
        // for (auto x : cost) cout << x << " "; cout << endl;
        
        int min_cost = max_size;
        for (int i=1;i<=9;++i) min_cost = min(min_cost, cost[i]);
        int max_len = target/min_cost;
        cout << max_len <<endl;
        
        vector<vector<int>> f(max_len+1, vector<int>(target+10,-1));
        for(int i=1;i<=9;++i) f[1][cost[i]] = i;
        
        for(int len=2;len<=max_len;++len){
            for (int prev = 0; prev<target; ++prev)
                if (f[len-1][prev] != -1){
                    for (int d=1;d<=9;++d){
                        if (prev + cost[d] <= target)
                            f[len][prev+cost[d]] = max(f[len][prev+cost[d]], d);
                    }
                }
        }
        cout << "HERE" << endl;
        
        for (int i=max_len;i>=0;--i)
            if (f[i][target] != -1){
                return construct_ans(f,i,target);
            }
        
        return "0";
    }
};
