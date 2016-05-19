class Solution {
public:
    int findDuplicate(vector<int>& a) 
    {
        int cnt[32];
        for (int i=0;i<32;++i) cnt[i] = 0;
        int n = a.size() - 1;
        for (int i=0;i<a.size();++i)
        {
            for (int j=0;j<32;++j)
                if ((a[i] & (1<<j))!=0) ++cnt[j];
        }
        
        int std[32];
        for (int i=0;i<32;++i) std[i] = 0;
        for (int i=1;i<=n;++i)
            for (int j=0;j<32;++j)
                if ((i & (1<<j))!=0) ++std[j];
        
        int ret = 0;
        for (int i=0;i<32;++i)
            if (cnt[i] > std[i])
                ret += (1<<i);
        return ret;
    }
};