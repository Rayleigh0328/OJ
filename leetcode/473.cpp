class Solution {
    
    bool result;
    void solve(vector<int>& state, const vector<int>&a, int pos, int target){
        if (result) return;
        
        if (state[0] == state[1] && state[1] == state[2] && state[0] == target) {
            result = true;
            return;
        }
        
        int cur = a[pos];
        for (int i=0;i<4;++i)
            if (cur + state[i] <= target){
                state[i] += cur;
                solve(state, a, pos+1, target);
                state[i] -= cur;
            }
        
    }
    
public:
    bool makesquare(vector<int>& a) {
        sort(a.begin(), a.end(), [](int x, int y){return x > y;});
        int sum = 0;
        for (int x : a) sum += x;
        if (sum % 4 != 0) return false;
        int target = sum / 4;
        if (target <= 0) return false;
        vector<int> state{0,0,0,0};
        result = false;
        solve(state, a, 0, target);
        return result;
    }
};
