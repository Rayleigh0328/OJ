class Solution {
public:
    int searchInsert(vector<int>& a, int target) 
    {
        if (a.size() == 0) return 0;
        if (target > a[a.size()-1]) return a.size();
        int left = 0;
        int right = a.size()-1;
        int mid;
        while (left <= right)
        {
            if (left == right) return left;
            if (right == left + 1)
                return (a[left]>=target?left:right);
            mid = (left + right)/2;
            if (a[mid] < target) left = mid + 1;
            else right = mid;
        }
    }
};