class Solution {
private:
    const int inf = 1<<30;
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int *a = new int [2*n+1];
        for (int i=0;i<n;++i) 
            a[i] = gas[i] - cost[i];
        for (int i=n;i<2*n;++i)
            a[i] = a[i-n];
        a[2*n] = -inf;
        
        int p1=0,p2=0,sum=0;
        while (p1<2*n)
        {
            sum += a[p2++];
            if (sum < 0)
            {
                p1 = p2;
                p2 = p1;
                sum=0;
                continue;
            }
            if (p2 - p1 == n) return p1 % n;
        }
        
        return -1;
    }
};