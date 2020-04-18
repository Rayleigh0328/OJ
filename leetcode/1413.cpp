class Solution {
public:
    int minStartValue(vector<int>& a) {
        int result = 10000, sum = 0;
        for (auto x : a){
            sum += x;
            result = min(result, sum);
        }
        if (result >= 0) return 1;
        return -result + 1;
    }
};
