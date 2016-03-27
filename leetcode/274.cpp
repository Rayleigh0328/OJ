class Solution {
public:
    int hIndex(vector<int>& a) 
    {
        if (a.empty()) return 0;
        std::sort(a.begin(), a.end(), std::greater<int>());
        int left = 0, right = a.size()-1;
        if (a[0] == 0) return 0;
        while (true)
        {
            if (left == right) return left+1;
            if (left == right - 1)
                return (a[right]>=right+1)?right+1:left+1;
            int mid = (left + right)/2;
            if (a[mid]>=mid+1) left = mid;
            else right = mid;
        }
    }
};