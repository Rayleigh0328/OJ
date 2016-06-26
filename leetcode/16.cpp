class Solution {
private:
    const int inf = (1<<30);
    void cmp(int a, int b, int c, int &ans, int target)
    {
        if (abs(a+b+c-target) < abs(ans-target)) ans = a+b+c;
    }
public:
    int threeSumClosest(vector<int>& a, int target) 
    {
        if (a.size() < 3) return inf;
        int ans = a[0] + a[1] + a[2];
        
        sort(a.begin(), a.end());
        for (int i=0;i<a.size()-2;++i)
        {
            int left = i+1;
            int right = a.size() - 1;
            while (left < right)
            {
                while (right > left && a[i] + a[left] + a[right] >= target) --right;
                if (right > left) cmp(a[i],a[left],a[right], ans, target);
                if (right + 1 > left && right + 1 < a.size()) cmp(a[i],a[left],a[right+1], ans, target);
                ++left;
            }
        }
        
        return ans;
    }
};