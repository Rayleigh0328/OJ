class Solution {
    
    const int inf = (1<<30);
    
public:
    int wiggleMaxLength(vector<int>& a) {
        if (a.empty()) return 0;
        
        int n = a.size();
        vector<int> up(n+1, -inf);
        vector<int> down(n+1, inf);
        
        int p_up=1, p_down=1;
        
        for (int val : a){
            if (val < up[p_up]){
                down[p_up + 1] = min(down[p_up+1], val);
                p_down = max(p_down, p_up + 1);
            }
            if (val > down[p_down]){
                up[p_down+1] = max(up[p_down+1], val);
                p_up = max(p_up, p_down+1);
            }
            if (val > up[p_up]) up[p_up] = val;
            if (val < down[p_down]) down[p_down] = val;
        }
        return max(p_up, p_down);
    }
};
