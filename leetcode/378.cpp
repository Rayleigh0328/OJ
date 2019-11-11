class Solution {
    int n,m;
    
    int count(int limit, vector<vector<int>> &a){
        int col = m-1;
        int ans = 0;
        for (int i=0;i<n;++i){
            while (col>=0 && a[i][col] > limit) --col;
            if (col < 0) break;
            ans += col + 1;
        }
        return ans;
    }
    
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        n = a.size();
        if (n == 0) return -1;
        m = a[0].size();
        if (m == 0) return -1;
        
        int left=a[0][0], right=a[n-1][m-1] + 1, mid;
        while (left < right){
            if (left + 1 == right) return left;
            if (left + 2 == right){
                if (count(left, a) >= k) return left;
                else return left+1;
            }
            
            mid = left + ((right-left) >> 1);
            if (count(mid, a) >= k) right = mid+1;
            else left = mid + 1;
        }
        return -1;
    }
};
