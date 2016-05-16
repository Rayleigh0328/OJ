class Solution {
private:
    const int inf = (1<<30);
public:
    int minSubArrayLen(int s, vector<int>& a) 
    {
        if (a.empty()) return 0;
        
        int p1 = 0, p2 = 0, sum = 0;
        for (; p2 < a.size(); ++p2)
        {
            if (sum + a[p2] >= s) break;
            sum += a[p2];
        }
        
        if (p2 == a.size()) return 0;
        
        int ans = inf;
        for (; p2 < a.size(); ++p2)
        {
            sum += a[p2];
            while (sum - a[p1] >= s)
                sum -= a[p1++];
            ans = min(ans, p2-p1+1);
        }
        return ans;
    }
};