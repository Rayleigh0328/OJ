class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& p) 
    {
        int len = p.size();
        
        int * ind = new int [len];
        for (int i=0;i<len;++i) ind[i] = 0;
        
        int * que = new int [n];
        que[0] = 1;
        int pr = 1;
        
        for (int i=1;i<n;++i)
        {
            for (int j=0;j<len;++j)
                while (que[ind[j]] * p[j] <= que[pr-1]) ++ind[j];
            int min_pos = 0;
            for (int j=1;j<len;++j)
                if (que[ind[min_pos]] * p[min_pos] > que[ind[j]] * p[j]) min_pos = j;
            que[pr++] = que[ind[min_pos]] * p[min_pos];
        }
        
        return que[n-1];
    }
};
