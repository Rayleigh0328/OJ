/*
 * init two pointer to the leftmost and rightmost 
 * move the pointer closer 
 * it is easy to see, move the pionter to higher height will not give a better result
 * always move the pointer to the lower height
 * in case of tie, move any one, it will not give better result though. 
 */
class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans = 0;
        int left = 0, right = h.size() -1;
        while (left < right){
            ans = max(ans, min(h[left], h[right]) * (right - left));
            if (h[left] < h[right]) ++left;
            else --right;
        }
        return ans;
    }
};


