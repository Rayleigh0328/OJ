class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = 0;
        for (auto x : left) result = max(result, x);
        for (auto x : right) result = max(result, n - x);
        return result;
    }
};
