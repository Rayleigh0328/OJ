class Solution {
    
    int dist(int x, int y){
        return abs(x - y);
    }
    
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        if (k < 1) return {};
        int p1 = 0, p2 = a.size()-1;
        while (p2-p1+1 > k){
            if (dist(a[p2],x) >= dist(a[p1],x)) --p2;
            else ++p1;
        }
        vector<int> ans;
        for (int i=p1;i<=p2;++i)
            ans.push_back(a[i]);
        return ans;
    }
};
