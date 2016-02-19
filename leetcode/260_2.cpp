class Solution {
public:
    vector<int> singleNumber(vector<int>& a) {
        int sum = 0;
        for (int i=0;i<a.size();++i)
            sum ^= a[i];
        int mask = sum & -sum;
        
        int x=0, y=0;
        for (int i=0;i<a.size();++i)
            if (a[i] & mask)
                x ^= a[i];
            else
                y ^= a[i];
        
        return vector<int>{x,y};
    }
};