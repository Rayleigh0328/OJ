class Solution {
public:
    bool isPerfectSquare(int num) {
        long long left = 1ll;
        long long right = num;
        long long mid;
        while (left <= right){
            mid = (left + right)/2;
            if (mid * mid == num) return true;
            else if (mid * mid < num) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
