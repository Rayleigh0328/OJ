class Solution {
public:
    int maxProfit(vector<int>& a) {
        if (a.size() == 0) return 0;
        int n = a.size();
        a.push_back(-1);
        int p1 = 0; 
        int p2;
        int ans = 0;
        while (p1 < n){
            p2 = p1 + 1;
            while (p2 < n && a[p2-1] <= a[p2]) ++p2;
            ans += a[p2-1] - a[p1];
            p1 = p2;
        }
        
        return ans;
    }
};
