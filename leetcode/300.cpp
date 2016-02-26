class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (auto a : nums) {
            auto i = lower_bound(sub.begin(), sub.end(), a);
            if (i == sub.end()) sub.push_back(a);
            else *i = a; // substitution
        }
        return sub.size();
    }
};