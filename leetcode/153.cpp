class Solution {
public:
    int findMin(vector<int>& a) 
    {
        int left = 0, right = a.size()-1;
        if (a[left] < a[right]) return a[left];
        while (true)
        {
            if (left == right) return a[left];
            if (left == right - 1) return min(a[left],a[right]);
            int mid = (left + right)/2;
            if (a[left] < a[mid]) left = mid;
            else right = mid;
        }
    }
};