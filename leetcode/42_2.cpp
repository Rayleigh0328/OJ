class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int max_left = 0;
        int right = n-1;
        int max_right = 0;
        int ans = 0;
        while (left <= right){
            if (max_left < max_right){
                if (height[left] > max_left)
                    max_left = height[left];
                else
                    ans += max_left - height[left];
                ++left;
            }
            else{
                if (height[right] > max_right)
                    max_right = height[right];
                else
                    ans += max_right - height[right];
                --right;
            }
        }
        return ans;
    }
};
