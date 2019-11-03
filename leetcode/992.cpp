class Solution {
    
    int solve_at_most(vector<int>&a, int k){
        if (k == 0) return 0;
        unordered_map<int,int> count;
        int n = a.size();
        int p1 = 0, p2 = 0;
        int ans=0;
        while (p2 < n){
            while (p2 < n && (count.size()<k || count.find(a[p2]) != count.end())){
                ans += p2-p1+1;
                ++count[a[p2++]];
            }
            while (count[a[p1]] > 1) --count[a[p1++]];
            count.erase(a[p1++]);
        }
        return ans;
    }
    
public:
    int subarraysWithKDistinct(vector<int>& a, int k) {
        return solve_at_most(a,k) - solve_at_most(a,k-1);
    }
};
