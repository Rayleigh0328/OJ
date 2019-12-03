class Solution {
public:
    int magicalString(int n) {
        vector<int> a{1,2,2};
        int p1 = 2,p2 = 3;
        while (p2 < n){
            int tmp = 1+(a[p2-1]&1);
            for (int i=0;i<a[p1];++i)
                a.push_back(tmp);
            p2 = a.size();
            ++p1;
        }
        int ans = 0;
        for (int i=0;i<n;++i)
            ans += (a[i] & 1);
        return ans;
    }
};
