class Solution {
    
    void sum(int x, int y, int &result, int& carry){
        result = (x ^ y);
        carry = ((x & y & 0x7fffffff) << 1);
    }
    
public:
    int getSum(int a, int b) {
        int result, carry;
        sum(a,b,result, carry);
        while (carry != 0){
            sum(result, carry, result, carry);
        }
        return result;
    }
};
