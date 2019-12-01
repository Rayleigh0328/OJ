/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
    
    int solve(Sea &sea, int xl, int xh, int yl, int yh){
        if (xl > xh || yl > yh) return 0;
        if (!sea.hasShips({xh, yh}, {xl, yl})) return 0;
        
        if (xl == xh && yl == yh) return 1;
        int xm = (xl + xh) / 2;
        int ym = (yl + yh) / 2;
        return solve(sea, xl, xm, yl, ym) 
            + solve(sea, xl, xm, ym+1, yh)
            + solve(sea, xm+1, xh, yl, ym)
            + solve(sea, xm+1, xh, ym+1, yh);
    }    
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        int x0 = topRight[0];
        int y0 = topRight[1];
        int x1 = bottomLeft[0];
        int y1 = bottomLeft[1];
        
        return solve(sea, x1, x0, y1, y0);
    }
};
