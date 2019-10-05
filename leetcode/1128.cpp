class Solution {
    typedef pair<int,int> Dom;
public:
    int numEquivDominoPairs(vector<vector<int>>& a) {
        map<Dom, int> dom_count;
        int x, y;
        for (int i=0;i<a.size();++i){
            x = a[i][0];
            y = a[i][1];
            if (x > y){
                int tmp = x;
                x = y;
                y = tmp;
            }
            Dom d = Dom(x,y);
            if (dom_count[d] == NULL) dom_count[d] = 1;
            else ++dom_count[d];
        }
        
        int ans = 0;
        for (const auto &x : dom_count){
            ans += x.second * (x.second-1) / 2;
        }
        return ans;
    }
};
