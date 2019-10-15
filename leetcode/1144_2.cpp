class Solution {
    
    int solve(int type, const vector<int>& a){
        int ans=0;
        if (type == 0) ans += max(0, a[0] - a[1] + 1);
        if ((a.size()-1) % 2 == type)
            ans += max(0, a[a.size()-1] - a[a.size()-2] + 1);
        for (int i=1;i<a.size()-1;++i)
            if ((i & 1) == type){
                ans += max(0, (a[i] - min(a[i-1], a[i+1]) + 1));
            }
        // printf("%d --> %d\n", type, ans);
        return ans;
    }
    
public:
    int movesToMakeZigzag(vector<int>& a) {
        return min(solve(1, a), solve(0, a));
    }
};
