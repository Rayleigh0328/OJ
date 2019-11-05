class Solution {
    
    int solve(int n, bool forward){
        if (n == 1) return 1;
        if (forward){
            return solve(n/2, false) * 2;
        }
        else {
            if ((n & 1) == 0){
                return solve(n/2, true) * 2 -1;
            }
            else{
                return solve(n/2, true) * 2;
            }
        }
    }
    
public:
    int lastRemaining(int n) {
        return solve(n, true);
    }
};
