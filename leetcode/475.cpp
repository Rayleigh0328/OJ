class Solution {
    
public:
    int findRadius(vector<int>& a, vector<int>& b) {
        long long inf = 2000000008;
        sort(a.begin(), a.end());
        b.push_back(inf);
        sort(b.begin(), b.end());
        
        int n = a.size();
        int m = b.size();
        int p = 0;
        int ans = 0;
        for (int i=0;i<m-1;++i){
            int right = floor(b[i] + (b[i+1]-b[i])/2.0);
            while (p < n && a[p] <= right)
                ans = max(ans, abs(a[p++]-b[i]));
        }
        return ans;
    }
};
