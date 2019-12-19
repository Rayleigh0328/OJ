class Solution {
    const int inf = (1<<30);
public:
    vector<int> numMovesStonesII(vector<int>& a) {
        
        int n = a.size();
        sort(a.begin(), a.end());
        
        if (a.back() - a[0] == a.size()-1) return {0,0};
        
        int max_step = 0;
        for (int i=1;i<a.size();++i)
            max_step += a[i] - a[i-1] - 1;
        max_step -= min(a[1]-a[0], a[n-1]-a[n-2])-1;
        
        
        a.push_back(inf);
        int min_step = inf;
        int left = 0, right=0;
        while (left < a.size()-1){
            right = max(right, left + 1);
            while (a[right] - a[left] < n) ++right;
            // printf("a[%d] = %d, a[%d]=%d\n", left, a[left], right, a[right]);
            int tmp = n - right + left;
            if (a[right-1]-a[left] == right-1-left) tmp = max(tmp, 2);
            min_step = min(min_step, tmp);
            ++left;
        }
        return {min_step, max_step};
    }
};
