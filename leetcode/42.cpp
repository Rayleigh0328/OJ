class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int n = height.size();
        vector<int> max_before(n);
        vector<int> max_after(n);
        max_before[0] = height[0];
        for (int i=1;i<n;++i) max_before[i] = max(max_before[i-1], height[i]);
        max_after[n-1] = height[n-1];
        for (int i=n-2; i>=0; --i) max_after[i] = max(max_after[i+1], height[i]);
        int ans = 0;
        for (int i=0;i<n;++i)
            ans += min(max_before[i], max_after[i]) - height[i];
        return ans;
    }
};
