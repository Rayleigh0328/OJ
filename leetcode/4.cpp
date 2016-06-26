class Solution {
private:
    int count_less_than(vector<int>& a, int l, int r, int val)
    {
        int mid;
        int ans = 0;
        
        while (l < r)
        {
            mid = (l+r)/2;
            if (a[mid] < val)
            {
                ans += mid - l + 1;
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        
        return ans;
    }
    
    int find_k(vector<int>& arr1, int l1, int r1, vector<int>& arr2, int l2, int r2, int k)
    {
        // ensure arr2 is longer than arr1
        if (r1 - l1 < r2 - l2) return find_k(arr2, l2, r2, arr1, l1, r1, k);
     
        if (k == 1) 
            if (r2 > l2 && arr2[l2] < arr1[l1]) return arr2[l2];
            else return arr1[l1];
        
        // find median of arr1
        int mid = (l1 + r1) / 2;
        
        int median = arr1[mid];
        
        int cnt_1 = mid - l1;
        int cnt_2 = count_less_than(arr2, l2, r2, median);
        
        // printf("l1:%d r1:%d l2:%d r2:%d k:%d cnt_1:%d cnt_2:%d\n", l1, r1, l2, r2, k, cnt_1, cnt_2);
        
        if (cnt_1 + cnt_2 == 0)
        {
            return find_k(arr1, l1+1, r1, arr2, l2, r2, k-1);
        }
        
        if (cnt_1 + cnt_2 == k-1) return median;
        
        if (cnt_1 + cnt_2 > k-1)
            return find_k(arr1, l1, mid, arr2, l2, l2 + cnt_2, k);
        else
            return find_k(arr1, mid, r1, arr2, l2+cnt_2, r2, k - cnt_1 - cnt_2);
    }
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int a = nums1.size();
        int b = nums2.size();
        if ((a+b)%2 == 1)
        {
            return find_k(nums1, 0, a, nums2, 0, b, (a+b)/2+1);
        }
        else
        {
            int left = find_k(nums1, 0, a, nums2, 0, b, (a+b)/2);
            int right = find_k(nums1, 0, a, nums2, 0, b, (a+b)/2 + 1);
            return ((double)left + right) /2;
        }
    }
};