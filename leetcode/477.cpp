class Solution {

    int f[32][2];
    
public:
    int totalHammingDistance(vector<int>& nums) {
        for (int i=0;i<32;++i)
            f[i][0] = f[i][1] = 0;
        for (int x : nums){
            for (int i=0;i<32;++i)
                if (x & (1<<i)) ++f[i][1];
                else ++f[i][0];
        }
        int ans = 0;
        for (int i=0;i<32;++i)
            ans += f[i][0] * f[i][1];
        return ans;
    }
};
