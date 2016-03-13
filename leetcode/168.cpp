class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while (n > 0)
        {
            ans = char((n-1)%26 + 'A') + ans;
            n = (n-1) / 26;
        }
        return ans;
    }
};