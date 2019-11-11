// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n, mid;
        while (left <= right){
            mid = left + ((right-left) >> 1);
            if (guess(mid) == 0) return mid;
            else if (guess(mid) == 1) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};