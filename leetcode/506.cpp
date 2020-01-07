class Solution {
    
    string convert(int rk){
        if (rk == 1) return "Gold Medal";
        if (rk == 2) return "Silver Medal";
        if (rk == 3) return "Bronze Medal";
        return to_string(rk);
    }
    
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> a(nums);
        sort(a.begin(), a.end(), greater<int>());
        unordered_map<int, int> rank;
        for (int i=0;i<a.size();++i)
            rank[a[i]] = i+1;
        vector<string> result;
        for (auto x : nums)
            result.push_back(convert(rank[x]));
        return result;
    }
};
