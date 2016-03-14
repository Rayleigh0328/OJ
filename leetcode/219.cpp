class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& a, int k) {
        map<int, int> pos;
        pos.clear();
        for (int i=0;i<a.size();++i)
            if (pos.find(a[i]) == pos.end())
                pos.emplace(a[i],i);
            else
            {
                int prev = pos[a[i]];
                if (i-prev <= k) return true;
                pos[a[i]] = i;
            }
        return false;
    }
};