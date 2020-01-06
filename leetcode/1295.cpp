class Solution {
    int count_digit(int k){
        if (k == 0) return 1;
        int result = 0;
        while (k > 0){
            result += 1;
            k/=10;
        }
        return result;
    }
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (auto x : nums)
            if (count_digit(x) % 2 == 0) ++ans;
        return ans;
    }
};
