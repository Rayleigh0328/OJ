class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
    	vector<int>f(cost.size()+1,0);
    	for (int i=2;i<=cost.size();++i){
    		f[i] = min(f[i-1] + cost[i-1], f[i-2] + cost[i-2]);
    	}
    	// for (int x : f) cout << x << " "; cout << endl;
    	return f[cost.size()];
    }
};
