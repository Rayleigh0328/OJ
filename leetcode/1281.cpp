class Solution {
public:
    int subtractProductAndSum(int n) {
        string s = to_string(n);
        int sum = 0, product = 1;
        for (char ch : s){
            sum += ch - '0';
            product *= (ch - '0');
        }
        return product - sum;
    }
};
