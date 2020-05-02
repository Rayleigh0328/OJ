class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m = 0;
        for (auto x: candies) m = max(m,x);
        vector<bool> result;
        for (auto x: candies)
            result.push_back(x+extraCandies >= m);
        return result;
    }
};
