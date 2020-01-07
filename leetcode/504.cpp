class Solution {
    
    string solve(int x){
        string result;
        while (x > 0){
            result += x % 7 + '0';
            x /= 7;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        if (num < 0) return "-" + solve(-num);
        return solve(num);
    }
};
