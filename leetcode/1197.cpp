class Solution {
public:
    int minKnightMoves(int x, int y) {
        // make sure x >= y >=0
        if (x < 0) x = -x;
        if (y < 0) y = -y;
        if (x < y) {
            int tmp = x;
            x = y;
            y = tmp;
        }
        // special case
        if ( x == 1 && y == 0) return 3;
        if ( x == 2 && y == 0) return 2;
        int delta = x - y;
        if (y > delta) return ceil((y - delta) / 3.0) * 2  + delta;
        else return delta - (delta - y)/4 * 2;
    }
};
