class Solution {

    long long a,b,c;

    long long gcd(long long x, long long y){
        if (x % y == 0) return y;
        else return gcd(y, x % y);
    }

    long long lcm(long long x, long long y){
        return x * y / gcd(x,y);
    }

    long long lcm(long long x, long long y, long long z){
        return lcm(lcm(x,y), z);
    }


    int count(long long x){
        long long ans = 0;
        ans += x / a;
        ans += x / b;
        ans += x / c;
        ans -= x / lcm(a,b);
        ans -= x / lcm(b,c);
        ans -= x / lcm(c,a);
        ans += x / lcm(a,b,c);
        return (int)ans;
    }

    int get_ans(long long x){
        long long tmp1 = x / a * a;
        long long tmp2 = x / b * b;
        long long tmp3 = x / c * c;
        if (tmp1 >= tmp2 && tmp1 >= tmp3) return tmp1;
        if (tmp2 >= tmp1 && tmp2 >= tmp3) return tmp2;
        return tmp3;
    }

public:
    int nthUglyNumber(int n, int aa, int bb, int cc) {
        a = aa;
        b = bb;
        c = cc;
        long long left = 1;
        long long right = 2 * 1000000000 + 1;
        long long mid;
        long long current_count;
        while (left < right){
            if (left == right -1) return left;
            mid = (left + right)/2;
            current_count = count(mid);
            //printf("left: %lld, right: %lld, mid: %lld, mid count: %lld\n", left, right, mid, current_count);
            if (current_count == n) return get_ans(mid);
            else if (current_count < n) left = mid + 1;
            else right = mid;
        }
        return -1;
    }
};
