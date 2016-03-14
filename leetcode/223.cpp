class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x1, x2, x3, x4, y1, y2, y3, y4;
        if (A <= E)
        {
            x1 = A; x2 = C; y1 = B; y2 = D;
            x3 = E; x4 = G; y3 = F; y4 = H;
        }
        else
        {
            x3 = A; x4 = C; y3 = B; y4 = D;
            x1 = E; x2 = G; y1 = F; y2 = H;
        }
        
        int ans = (x2 - x1) * (y2 - y1) + (x4 - x3) * (y4-y3);
        // no overlap
        if (x2 <= x3 || y4 <= y1 || y2 <= y3) return ans;
        int sub;
        // y3 in between
        if  (y1 <= y3 && y3 <=y2)
            sub = (min(x2,x4) - x3) * (min(y2,y4) - y3);
        else 
            if (y1 <= y4 && y4 <= y2)
                sub = (min(x2,x4) - x3) * (y4 - max(y1,y3));
            else
                sub = (min(x2,x4) - x3) * (y2 - y1);
        return ans - sub;
    }
};