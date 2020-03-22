class Solution {
    
    double eps = 1e-6;
    
    int solve(int x){
        int result = x + 1;
        int count = 0;
        for (int i=2;i<=sqrt(x) + eps;++i){
            if (x % i == 0) {
                ++count;
                result += i;
                if (i * i != x){
                    ++count;
                    result += x / i;
                }
            }
        }
        if (count != 2) return 0;
        return result;
    }
    
public:
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for (auto x : nums)
            result += solve(x);
        return result;
    }
};
