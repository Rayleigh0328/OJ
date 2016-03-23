class Solution {
public:
    bool canJump(vector<int>& a) 
    {
        int n = a.size();
        if (n == 1) return true; 
        int last = 0;
        int step = 0;
        int pos = 0;
        while (true)
        {
            int next = 0;
            for (int i = pos; i<=last; ++i)
                next = max(next, a[i] + i);
            if (next >= n-1) return true;
            pos = last + 1;
            if (last == next) return false;
            last = next;
            ++step;
        }
        return false;
    }
};