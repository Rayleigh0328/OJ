class Solution {
    unordered_map<char, int> count;
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0, max_count = 0, ans = 0;
        while (right < s.size()){
            max_count = max(max_count, ++count[ s[right++] ]);
            if (right - left - max_count > k) --count[s[left++]];
            // printf("left :%d, right: %d, max_count: %d\n", left, right, max_count);
            ans = max(ans, right-left);
        }
        return ans;
    }
};
