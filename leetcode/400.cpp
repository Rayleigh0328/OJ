class Solution {
    int MAX_SIZE=11;
public:
    int findNthDigit(int n) {
        long long count[MAX_SIZE];
        count[0] = 0;
        count[1] = 9;
        for (int i=2;i<MAX_SIZE;++i)
            count[i] = count[i-1] * 10;
        int len = 1;
        while (n > len * count[len]){
            n -= count[len] * len;
            ++len;
        }
        int base = 1;
        for (int i=1;i<len;++i)
            base *= 10;

        
        int x = (n-1) / len + base;
        return to_string(x)[(n-1)%len]-'0';
    }
};



// 1 ~ 9 ==> 9 * 1 digits
// 10 ~ 99 ==> 90 * 2 digits
// 100 ~ 999 ==> 900 * 3 digits

