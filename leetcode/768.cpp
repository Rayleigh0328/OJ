class Solution {
public:
    int maxChunksToSorted(vector<int>& a) {
        const int n = a.size();
        
        vector<int> b(a);
        sort(b.begin(), b.end());
        
        vector<int> suffix(n);
        suffix[n-1] = a[n-1];
        for (int i=n-2;i>=0;--i)
            suffix[i] = min(a[i], suffix[i+1]);
        
        int left = 0, right, max_a, max_b;
        int result = 0;
        while (left < n){
            right = left+1;
            max_a = a[left];
            max_b = b[left];
            while (right < n && ( max_a != max_b || max_a > suffix[right])){
                max_a = max(max_a, a[right]);
                max_b = max(max_b, b[right]);
                ++right;
            }
            left = right;
            ++result;
        }
        
        return result;
    }
};
