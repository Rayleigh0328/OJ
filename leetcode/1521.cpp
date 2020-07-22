class Solution {
    
    const int inf = (1<<28);
    
    vector<int> a;
    int n;
    int t;
    vector<vector<int>> st;
    
    int rmq(int left, int right){
        int len = right - left + 1;
        int k = 0;
        while ((1<<k) <= len) ++k;
        --k;
        return (st[k][left] & st[k][right - (1<<k) + 1]);
    }
    
    int solve(int start){
        int result = inf;
        int left = start, right = n, mid;
        while (left < right){
            if (left + 2 >= right) {
                result = min(result, try_solution(rmq(start, left)));
                if (left + 1 < n) result = min(result, try_solution(rmq(start, left + 1)));
                if (left + 2 < n) result = min(result, try_solution(rmq(start, left + 2)));
                break;
            }
            mid = left + (right-left)/2;
            if (rmq(start, mid) >= t)
                left = mid;
            else 
                right = mid;
        }
        return result;
    }
    
    int try_solution(int k){
        return abs(k - t);
    }
    
public:
    int closestToTarget(vector<int>& arr, int target) {
        a = arr;
        n = a.size();
        t = target;
        
        // construct st table
        st.push_back(a);
        while ((1<<(st.size()-1)) < n){  
            st.push_back(vector<int>(n));
            int p = st.size()-1;
            for (int i=0;i<n;++i)
                if (i + (1<<(p-1)) < n)
                    st[p][i] = (st[p-1][i] & st[p-1][i + (1<<(p-1))]);
                else 
                    st[p][i] = st[p-1][i];
        }
        
        int result = inf;
        for (int i = 0; i < n; ++i){
            result = min(result, solve(i));
        }
        return result;
    }
};
