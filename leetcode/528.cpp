class Solution {
    map<int, int> mp;
    int sum;
public:
    Solution(vector<int>& w) {
        sum = 0;
        for (int i=0;i<w.size();++i){
            sum += w[i];
            mp[sum] = i;
        }
    }
    
    int pickIndex() {
        int x = rand() % sum;
        return mp.upper_bound(x) -> second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
