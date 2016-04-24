class Solution {
public:
    bool isPowerOfFour(int num) 
    {
        if (num <= 0) return false;
        int low_bit = num & -num;
        if (low_bit != num) return false;
        return (num & 0x55555555) != 0;
    }
};