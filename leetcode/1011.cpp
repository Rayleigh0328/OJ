class Solution {
    const int inf = (1<<29);
    
    bool check(int limit, const vector<int> &a, int days){
        int sum = 0;
        int count_days = 0;
        for (auto e : a){
            if (e > limit) return false;
            if (sum+e <= limit) sum+=e;
            else {
                ++count_days;
                sum = e;
            }
        }
        return count_days < days;
    }
public:
    int shipWithinDays(vector<int>& weights, int d) {
        int left = 0;
        int right = inf;
        int mid;
        while (left < right){
            if (left + 1 == right) return left;
            if (left + 2 == right){
                if (check(left, weights, d)) return left;
                else return left+1;
            }
            mid = (left + right)/2;
            if (check(mid, weights, d)) right = mid + 1;
            else left = mid+1;
        }
        return -1;
    }
};
