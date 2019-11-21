class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        for (int i=0;i<a.size();){
            int x = a[i];
            if (a[x-1] == x) ++i;
            else swap(a[i], a[x-1]);
        }
        vector<int> ans;
        for (int i=0;i<a.size();++i)
            if (a[i] != i+1) ans.push_back(a[i]);
        return ans;
    }
};
