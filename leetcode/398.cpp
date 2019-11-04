class Solution {
    unordered_map<int, vector<int>> value_to_indexes; 
public:
    Solution(vector<int>& a) {
        for (int i=0;i<a.size();++i)
            value_to_indexes[a[i]].push_back(i);
    }
    
    int get_random(const vector<int>& v){
        int pos = rand() % v.size();
        return v[pos];
    }
    
    int pick(int target) {
        return get_random(value_to_indexes[target]);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
