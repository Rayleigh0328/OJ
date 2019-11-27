class Solution {
public:
    int hammingDistance(int x, int y) {
        int tmp = x ^ y;
        int ans = 0;
        while (tmp != 0){
            tmp -= (tmp & -tmp);
            ++ans;
        }
        return ans;
    }
};
