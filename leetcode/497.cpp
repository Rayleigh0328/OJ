class Solution {

    int n;
    vector<int> p_sum;
    int total_p;
    vector<vector<int>> a;
    
public:
    
    Solution(vector<vector<int>>& rects) {
        a = rects;
        n = rects.size();
        for (int i=0;i<n;++i){
            int p_cnt = (a[i][2]-a[i][0]+1) * (a[i][3] - a[i][1] + 1);
            // printf("area of %d th rect is %d\n", i, p_cnt);
            p_sum.push_back((p_sum.empty()?0:p_sum.back()) + p_cnt);
        }
        total_p = p_sum.back();
        // for (int i=0;i<n;++i)
        //     printf("p_sum[%d] = %d\n", i, p_sum[i]);
    }
    
    vector<int> pick() {
        int r = random() % total_p;
        // printf("random number: %d\n", r);
        for (int i=0;i<n;++i)
            if (p_sum[i] > r)
                if (i == 0) return translate(i, r);
                else return translate(i, r-p_sum[i-1]);
        return {};
    }
    
    vector<int> translate(int ind, int rank){
        int m = a[ind][3] - a[ind][1] + 1;
        int dy = rank % m;
        int dx = rank / m;
        return {a[ind][0] + dx, a[ind][1] + dy};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
