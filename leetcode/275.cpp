class Solution {
public:
    int hIndex(vector<int>& a) 
    {
        if (a.empty()) return 0;
        int left = 0, right = a.size()-1, n = a.size();
        if (a[right] == 0) return 0;
        while (true)
        {
            if (left == right) return n-left;
            if (left == right - 1)
                return (a[left]>=n-left)?n-left:n-right;
            int mid = (left + right)/2;
            if (a[mid]>=n-mid) right = mid;
            else left = mid;
        }
    }
};