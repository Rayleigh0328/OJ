class Solution {
public:
    void merge(vector<int>& ans, int n, vector<int>& b, int m) {
        
        vector<int> a;
        for (int i=0;i<n;++i)
            a.push_back(ans[i]);
        ans.clear();
        int p1=0,p2 = 0;
        while (p1 < n || p2 < m)
        {
            if (p1 == n) ans.push_back(b[p2++]);
            else 
                if (p2 == m) ans.push_back(a[p1++]);
                else
                    if (a[p1] < b[p2]) ans.push_back(a[p1++]);
                    else ans.push_back(b[p2++]);
        }
    }
};