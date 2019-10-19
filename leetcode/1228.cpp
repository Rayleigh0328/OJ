class Solution {
    
    bool check(const vector<int>& a){
        int delta = a[1]-a[0];
        for (int i=1;i<a.size();++i){
            if (delta != a[i] - a[i-1]) return false;
        }
        return true;
    }
    
    int solve(int pos, const vector<int>&a){
        if ((a[pos] + a[pos+1]) % 2 == 1) return -1;
        int result = (a[pos] + a[pos+1])/2;
        vector<int>b;
        for (int i=0;i<=pos;++i) b.push_back(a[i]);
        b.push_back(result);
        for (int i=pos+1; i<a.size();++i) b.push_back(a[i]);
        if (check(b)) return result;
        return -1;
    }
    
public:
    int missingNumber(vector<int>& a) {
        int ans;
        for (int i=0;i<a.size()-1;++i){
            ans = solve(i,a);
            if (ans >=0) break;
        }
        return ans;
    }
};
