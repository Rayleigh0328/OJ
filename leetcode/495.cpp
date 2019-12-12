class Solution {
public:
    int findPoisonedDuration(vector<int>& a, int d) {
        int start=-1, end=-1;
        int ans = 0;
        for (int x : a){
            if (x > end) {
                ans += end - start;
                start = x;
            }
            end = x + d;
        }
        return ans + end - start;
    }
};
