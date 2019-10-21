class Solution {
    
    bool check(long long sum_limit, const vector<int>& a, int m){
        long long sum = 0ll;
        int count = 1;
        for (auto x : a){
            if (x > sum_limit) return false;
            if (sum + x > sum_limit){
                sum = x;
                ++count;
            }
            else {
                sum += x;
            }
        }
        return count <= m;
    }
    
public:
    int splitArray(vector<int>& a, int m) {
        long long left = 0, right = (1ll<<62), mid;
        while (left < right){
            if (left+1 == right) return (int)left;
            if (left + 2 == right){
                if (check(left,a,m)) return (int)left;
                return (int)(left + 1);
            }
            mid = left + (right-left)/2;
            if (check(mid,a,m)) right = mid + 1;
            else left = mid + 1;
        }
        return -1;
    }
};
