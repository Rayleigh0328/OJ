class Solution {
    
    const int mode = 1000000007;
    
public:
    int numOfSubarrays(vector<int>& a) {
        int prefix_odd = 0, prefix_even = 1;
        int sum = 0;
        int result = 0;
        for (auto x : a){
            sum += x;
            if (sum & 1) result = (result + prefix_even) % mode;
            else result += prefix_odd;
            if (sum & 1) ++prefix_odd;
            else ++prefix_even;
        }
        return result;
    }
};
