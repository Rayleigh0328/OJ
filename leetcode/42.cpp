class Solution {
public:
    int trap(vector<int>& height) 
    {
         vector<int> h;
         h.clear();
         h.push_back(0);
         for (int i=0;i<height.size();h.push_back(height[i++]));
         int n = h.size();
         
         int *max_before = new int [n];
         int *max_after = new int [n];
         max_before[0] = h[0];
         for (int i=1;i<n;++i) max_before[i] = max(max_before[i-1],h[i]);
         max_after[n-1] = h[n-1];
         for (int i=n-2;i>=0;--i) max_after[i] = max(max_after[i+1],h[i]);
         
         int ans = 0;
         for (int i=0;i<n;++i)
            ans += min(max_before[i],max_after[i]) - h[i];
        delete [] max_before;
        delete [] max_after;
        return ans;
    }
};