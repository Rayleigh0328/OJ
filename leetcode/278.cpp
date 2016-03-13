// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
private:
    int solve(int left, int right)
    {
        if (left == right) return left;
        int mid = left + (right - left)/2;
        
        if (mid == right)
            if (isBadVersion(left)) return left;
            else return right;
            
        if (isBadVersion(mid))
            solve(left, mid);
        else
            solve(mid+1, right);
    }
public:
    int firstBadVersion(int n) {
        return solve(1,n);
    }
};