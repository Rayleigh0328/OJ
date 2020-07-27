class Solution {
public:
    int countOdds(int low, int high) {
        if (low == high) return (low & 1)?1:0;
        if ((low & 1) && (high & 1)) return (high - low - 1)/2 + 2;
        if (!(low & 1) && (high & 1)) return (high - low - 1)/2 + 1;
        if ((low & 1) && !(high & 1)) return (high - low - 1)/2 + 1;
        return (high - low) / 2;
    }
};
