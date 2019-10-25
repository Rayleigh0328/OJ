class Solution {
    
    int count(int limit, int row, int col){
        int right = col;
        int ans = 0;
        for (int i=1;i<=row;++i){
            while (i * right > limit) --right;
            if (right == 0) return ans;
            ans += right;
        }
        return ans;
    }
    
public:
    int findKthNumber(int row, int col, int k) {
        int left = 1, right = row * col + 1, mid;
        while (left < right){
            if (left + 1 == right) return left;
            if (left + 2 == right){
                if (count(left,row,col) >= k) return left;
                return left + 1;
            }
            mid = left + ((right - left) >> 1);
            if (count(mid, row, col)>=k) right = mid+1;
            else left = mid + 1;
        }
        return -1;
    }
};
