class Solution {
    
    int inf = (1<<30);
    
    int solve(const vector<int>& a, int start, int end, int delimiter){
        int left = start;
        int right = end;
        int mid;
        while (left < right){
            mid = left + ((right - left)>>1);
            // printf("left: %d, right: %d, mid: %d\n", left, right, mid);
            if (a[mid]<a[mid-1]) return a[mid];
            else if (a[mid] > delimiter) left = mid + 1;
            else right = mid;
        }
        return inf;
    }
public:
    int findMin(vector<int>& a) {
        if (a.empty()) return -inf;
        int delimiter = a[0];
        int left=0, right=a.size();
        while (left < a.size() && a[left] == delimiter) ++left;
        while (right > 0 && a[right-1] == delimiter) --right;
        if (left >= right) return delimiter;
        
        return min(delimiter, solve(a, left, right, delimiter));
    }
};
