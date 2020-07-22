class Solution {
    const int mode = 1000000007;
public:
    int numSub(string s) {
        int left=0, right, len;
        int result = 0;
        while (left < s.size()){
            if (s[left] == '0') {
                ++left;
                continue;
            }
            right = left;
            while (right < s.size() && s[right] == '1') ++right;
            len = right - left;
            result = (result + static_cast<long long>(len) * (len-1) / 2 + len) % mode;
            left = right;
        }
        return result;
    }
};
