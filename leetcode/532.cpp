class Solution {
public:
    int findPairs(vector<int>& a, int k) {
        
        if (k < 0) return 0;
        unordered_map<int, int> count;
        for (auto x : a) ++count[x];
        
        int result = 0;
        if (k == 0){
            for (auto &e : count)
                if (e.second >= 2) ++result;
            return result;
        }
        
        for (auto &e : count){
            int target = e.first + k;
            if (count.find(target) != count.end()) ++result;
        }
        
        return result;
    }
};
