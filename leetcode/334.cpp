class Solution {
private:
    const long long inf = 1ll << 40;
public:
    bool increasingTriplet(vector<int>& a) {
        long long x = inf;
        long long y = inf;
        
        for (int i=0;i<a.size();++i)
        {
            if (a[i] < x) x = a[i];
            else 
                if (a[i] == x) continue;
                else 
                    if (a[i] <= y) y = a[i];
                    else 
                        return true;
        }
        return false;
    }
};