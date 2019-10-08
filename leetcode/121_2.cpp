class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        if (n == 0) return 0;
        int high = a[n-1];
        int ans = 0;
        for (int i=n-1;i>=0;--i){
            ans = max(ans, high-a[i]);
            if(a[i] > high) high = a[i];
        }
        return ans;
    }
};
