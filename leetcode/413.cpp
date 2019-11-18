class Solution {
    
    int choose3(int k){
        if (k < 3) return 0;
        int ans = k * (k-1) / 2;
        ans -= k-1;
        return ans;
    }
    
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int left = 0, right;
        int delta;
        int ans = 0;
        while (left + 1 < a.size()){
            delta = a[left + 1] - a[left];
            right = left+1;
            while (right < a.size() && a[right] - a[right-1] == delta) ++right;
            // printf("left: %d, right: %d\n", left, right);
            ans += choose3(right - left);
            left = right-1;
        }
        return ans;
    }
};
