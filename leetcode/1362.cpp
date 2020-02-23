class Solution {
    typedef vector<int> AnsType;
    const double eps = 1e-6;
    
    vector<int> solve(int k){
        vector<int> ans={-1,-1};
        for (int i=1;i<=sqrt(k)+eps;++i)
            if (k % i==0 && i>ans[0])
                ans={i,k/i};
        return ans;
    }
    
public:
    vector<int> closestDivisors(int num) {
        AnsType ans1 = solve(num+1);
        AnsType ans2 = solve(num+2);
        if (ans1[1]-ans1[0] < ans2[1]-ans2[0]) return ans1;
        else return ans2;
    }
};
