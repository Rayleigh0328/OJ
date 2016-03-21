class Solution {
public:
    int firstMissingPositive(vector<int>& a) 
    {
        for (int i=0;i<a.size();++i)
            if (a[i] > 0 && a[i] <= a.size() && a[i] != a[a[i]-1])
            {
                swap(a[a[i]-1], a[i]);
                --i;
            }
        for (int i=0;i<a.size();++i)
            if (a[i] != i+1) return i+1;
        return a.size()+1;
    }
};