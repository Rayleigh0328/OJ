class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& v, int k) {
        v.push_back(k + 1);
        long long current_product = 1;
        int left=0; 
        int right = left;
        int ans = 0;
        while (left < v.size()){
            while (v[right] * current_product < k) current_product *= v[right++];
//            printf("left %d, right %d\n", left, right);
            ans += right - left;
            if (left < right) current_product /= v[left++];
            else right = ++left;
//            printf("current product %lld\n", current_product);
        } 
        return ans;
    }
};
