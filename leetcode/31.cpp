class Solution {
private:
    void rev(vector<int>& a, int left)
    {
        int mid = (a.size() - 1 + left) / 2;
        for (int i = left; i <= mid; ++i)
            swap(a[i], a[a.size() - 1 + left - i]);
    }
public:
    void nextPermutation(vector<int>& a) 
    {
        int pos = a.size() - 2;
        while (pos >= 0 && a[pos] >= a[pos + 1]) --pos;
        if (pos < 0) 
        {
            reverse(a.begin(), a.end());
            return;
        }
        int pos2 = a.size() - 1;
        for (; pos2 > pos; --pos2)
            if (a[pos2] > a[pos]) break;
        // cout << pos << " " << pos2 << endl;
        swap(a[pos], a[pos2]);
        rev(a,pos+1);
    }
};