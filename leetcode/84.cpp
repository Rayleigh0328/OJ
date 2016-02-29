class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        
        int* a = new int [n+2];
        a[0] = -1;
        for (int i=0;i<heights.size();++i)
            a[i+1] = heights[i];
        a[n+1] = -1;
        n+=2;
        
        stack<int> s;
        while (!s.empty()) s.pop();
        
        int ans = 0;
        s.push(0);
        for (int i=1;i<n;++i)
        {
            int l,m;
    
            while (a[i] < a[s.top()])
            {
                m = s.top();
                s.pop();
                l = s.top();
                ans = max(ans, a[m] * (i-l-1));
            }
            s.push(i);
        }
        return ans;
    }
};