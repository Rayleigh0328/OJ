class Solution {
public:
    int jump(vector<int>& a) 
    {
        int n = a.size();
        if (n == 1) return 0; 
        int last = 0;
        int step = 0;
        int pos = 0;
        while (true)
        {
            int next = 0;
            for (int i = pos; i<=last; ++i)
                next = max(next, a[i] + i);
            if (next >= n-1) return step + 1;
            pos = last + 1;
            last = next;
            ++step;
        }
    }
};