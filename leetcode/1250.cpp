class Solution {
    
    int gcd(int x, int y){
        int r = x % y;
        if (r == 0) return y;
        else return gcd(y, r);
    }
    
public:
    bool isGoodArray(vector<int>& a) {
        if (a.empty()) return false;
        int ans = a[0];
        for (int i=1;i<a.size();++i)
            ans = gcd(ans, a[i]);
        return (ans == 1);
    }
};
