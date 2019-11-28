class Solution {
    
    int low(int x){
        return (x & -x);
    }
    
public:
    int findComplement(int num) {
        if (num == 0) return 1;
        int tmp = num, mask;
        while (tmp != low(tmp)) tmp -= low(tmp);
        if (tmp == (1<<30)) mask = 0x7fffffff;
        else mask = (tmp << 1) - 1;
        return (~num & mask);
    }
};
