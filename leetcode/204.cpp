class Solution {
public:
    int countPrimes(int n) {
        bool a[n];
        for (int i=2;i<n;a[i++]=true);
        int count = 0;
        for (int i=2;i<n;++i)
            if (a[i])
            {
                ++count;
                for (int j=i*2;j<n;j+=i) a[j] = false;
            }
        return count;
    }
};