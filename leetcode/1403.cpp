class Solution {
public:
    vector<int> minSubsequence(vector<int>& a) {
        sort(a.begin(), a.end(), greater<int>());
        int sum = 0;
        for (auto x : a) sum += x;
        int current = 0;
        vector<int> result;
        for (auto x : a){
            current += x;
            result.push_back(x);
            if (current * 2 > sum) break;
        }
        return result;
    }
};
