class Solution {
    
    typedef long long ll;
    
    void sum(ll x, ll y, ll &result, ll& carry){
        result = (x ^ y);
        carry = ((x & y) << 1);
        // prllf("sum %d, %d, result is %d, carry is %d\n", x,y,result,carry);
    }
    
    ll sum(ll x, ll y){
        assert(x >=0 && y>=0);
        ll result, carry;
        sum(x,y,result, carry);
        while (carry != 0){
            sum(result, carry, result, carry);
        }
        return result;
    }
    
    void subtract(ll x, ll y, ll &result, ll& carry){
        result = (x ^ y);
        carry = ((~x & y) << 1);
    }
    
    ll subtract(ll x, ll y){
        assert(x>=y && y>=0);
        ll result, carry;
        subtract(x,y,result,carry);
        while (carry != 0){
            subtract(result, carry, result, carry);
        }
        return result;
    }
    
    ll get_positive(ll x){
        assert(x <= 0);
        return sum(~x, 1);
    }
    
    ll get_negative(ll x){
        assert(x >=0);
        return (~subtract(x,1)); 
    }
    
    ll get_abs(ll x){
        if (x >= 0) return x;
        return get_positive(x);
    }
    
public:
    int getSum(int a, int b) {
        if (a >= 0 && b >=0) return sum(a,b);
        if (a <= 0 && b <=0) return get_negative(sum(get_positive(a),get_positive(b)));
        if (a < 0) swap(a,b);
        if (get_abs(a) >= get_abs(b)) return subtract(a,get_abs(b));
        else return get_negative(subtract(get_abs(b), get_abs(a)));
    }
};
