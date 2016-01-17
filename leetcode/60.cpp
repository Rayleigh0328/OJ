class Solution {
public:
    string getPermutation(int n, int k) {
        int *p = new int[n];
        p[0] = 1;
        for (int i=1;i<n;++i)
            p[i] = p[i-1] * i;
        
        int *ans = new int [n];
        for (int i=0;i<n;++i)
        {
            ans[i] = ((k-1) / p[n-i-1]) + 1;
            k = (k-1) % p[n-i-1] + 1;
        }
        
        bool* used = new bool [n+1];
        for (int i=0;i<n;++i) used[i] = false;
        for (int i=0;i<n;++i)
        {
            int pos=0, cnt = 0;
            while (cnt < ans[i])
                if (!used[++pos]) ++cnt;
            ans[i] = pos;
            used[pos] = true;
        }
        string result = "";
        for (int i=0;i<n;++i)
            result += ans[i] + '0';
        
        cout << result << endl;
        return result;
    }
};