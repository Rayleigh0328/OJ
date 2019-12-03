class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int ans = 0, cur = 0;
        for (int x : a){
            cur = (cur + x) * x;
            if (cur > ans) ans = cur;
        }
        return ans;
    }
};
