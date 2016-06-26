class Solution {
private:
    static bool cmp(const pair<int,int>& a, const pair<int, int>& b)
    {
        if (a.first < b.first) return true;
        if (a.first > b.first) return false;
        return a.second > b.second;
    }
    
public:
    int maxEnvelopes(vector<pair<int, int>>& env) 
    {
        if (env.empty()) return 0;
        
        sort(env.begin(), env.end(), cmp);
        
        vector<int> dp;
        for (auto a:env)
        {
            auto i = lower_bound(dp.begin(), dp.end(), a.second);
            if (i == dp.end()) dp.push_back(a.second);
            else *i = a.second;
        }
        
        return dp.size();
    }
};