class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> a{0, 123456789, 23456789, 3456789, 456789, 56789, 6789, 789, 89, 9};
        vector<int> cand;
        for (auto x : a){
            while (x > 0){
                cand.push_back(x);
                x /= 10;
            }
        }
        vector<int> result;
        for (auto x : cand)
            if (low <= x && x<=high)
                result.push_back(x);
        sort(result.begin(), result.end());
        return result;
    }
};
