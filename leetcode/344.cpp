class Solution {
public:
    string reverseString(string s) 
    {
        string ans = s;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};