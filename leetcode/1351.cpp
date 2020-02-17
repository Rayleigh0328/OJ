class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0;
        for (auto row : grid)
            for (auto x : row)
                if (x < 0) ++result;
        return result;
    }
};
