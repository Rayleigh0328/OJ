class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        vector<int> pos;
        pos.push_back(-1);
        for (int i=0;i<a.size();++i)
            if (a[i] & 1) pos.push_back(i);
        pos.push_back(a.size());
        // for (auto e : pos) cout << e << " "; cout << endl;
        if (pos.size() < k+2) return 0;
        int p1 = 0, p2 = k;
        int ans = 0;
        while (p2 < pos.size()-1){
            ans += (pos[p1+1] - pos[p1]) * (pos[p2+1] - pos[p2]);
            ++p1;
            ++p2;
        }
        return ans;
    }
};
