class Solution {
    
    int inf = (1<<30);
    
    int f(int start, int target, int current){
        if (target < start && current >= start) return -inf;
        if (target > start && current <= start) return inf;
        return current;
    }
    
public:
    int search(vector<int>& a, int target) {
        if (a.empty()) return -1;
        if (target == a[0]) return 0;
        int left = 1, right = a.size(), mid, nv;
        while (left < right){
            mid = left + ((right - left) >> 1);
            nv = f(a[0], target, a[mid]);
            if (nv == target) return mid;
            else if (nv < target) left = mid + 1;
            else right = mid;
        }
        return -1;
    }
};
