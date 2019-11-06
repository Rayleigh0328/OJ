class Solution {
    
    typedef long long ll;
    const ll inf = (1ll<<60);
    
    ll count(ll n){
        ll base = 5;
        ll ans = 0;
        while (base <= n){
            ans += n/base;
            base *= 5;
        }
        return ans;
    }
    
    ll get_min(int k){
        ll left = 0, right = inf, mid;
        while (left < right){
            if (left+1 == right) return left;
            if (left+2 == right){
                if (count(left)>=k) return left;
                return left+1;
            }
            
            mid = left + ((right - left) >> 1);
            if (count(mid) < k) left = mid + 1;
            else right = mid + 1;
        }
        return -1;
    }
    
public:
    int preimageSizeFZF(int k) {
        ll ub = get_min(k+1);
        ll lb = get_min(k);
        // printf("lb:%lld -> %lld, ub:%lld->%lld\n", lb, count(lb), ub, count(ub));
        return ub - lb;
    }
};
