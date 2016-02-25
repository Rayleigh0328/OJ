class Solution {
public:
    int minPatches(vector<int>& a, int n) {
        long long top = 0;
        int ans = 0;
        int i=0;
        while (top < n)
        {
            if (i < a.size() && a[i]<=top+1) top += a[i++];
            else
            {
                ++ans;
                top += top + 1;
            }
        }
        return ans;
    }
};