class Solution {
public:
    int numIdenticalPairs(vector<int>& a) {
        const int n = a.size();
        int result = 0;
        for (int i=0;i<n;++i)
            for (int j=i+1;j<n;++j)
                if (a[i] == a[j])
                    ++result;
        return result;
    }
};
