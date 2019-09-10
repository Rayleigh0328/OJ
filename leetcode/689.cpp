class Solution {
public:
    int INF = 2147483647;
    int base = 1000000;
    
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> a(nums.size());
        for (int i=0; i<k-1; ++i) a[i] = -INF;
        int tmp = 0;
        for (int i=0; i<k; ++i) tmp+=nums[i];
        a[k-1] = tmp;
        for (int i=k; i<a.size();++i)
            a[i] = a[i-1] - nums[i-k] + nums[i];
        
        // for (auto x:a) cout << x << " "; cout << endl;
 
        vector<int> f(nums.size());
        vector<long long> f_from(nums.size());
        f[0] = a[0];
        f_from[0] = 0;
        for (int i=1;i<nums.size();++i) {
            // f[i] = max(f[i-1], a[i]);
            if (f[i-1] >= a[i]) {
                f[i] = f[i-1];
                f_from[i] = f_from[i-1];
            }
            else {
                f[i] = a[i];
                f_from[i] = i;
            }
        }
        // cout << "f:" << endl;
        // for (auto x:f) cout << x << " "; cout << endl;
        // for (auto x:f_from) cout << x << " "; cout << endl<<endl;

        vector<int> g(nums.size());
        vector<long long> g_from(nums.size());
        for (int i=0;i<k;++i) g[i] = f[i];
        for (int i=k;i<nums.size();++i) {
            // g[i] = max(g[i-1], f[i-k] + a[i]);
            if (g[i-1] >= f[i-k] + a[i]){
                g[i] = g[i-1];
                g_from[i] = g_from[i-1];
            }
            else{
                g[i] = f[i-k] + a[i];
                g_from[i] = f_from[i-k] * base + i;
            }
        }
        // cout << "g:" << endl;
        // for (auto x:g) cout << x << " "; cout << endl;
        // for (auto x:g_from) cout << x << " "; cout << endl<<endl;
        
        vector<int> h(nums.size());
        vector<long long> h_from(nums.size());
        for (int i=0;i<k;++i) h[i] = g[i];
        for (int i=k;i<nums.size();++i) {
            // h[i] = max(h[i-1], g[i-k] + a[i]);
            if (h[i-1] >= g[i-k] + a[i]){
                h[i] = h[i-1];
                h_from[i] = h_from[i-1];
            }
            else{
                h[i] = g[i-k] + a[i];
                h_from[i] = g_from[i-k] * base + i;
            }
        }
        // cout << "h:" << endl;
        // for (auto x:h) cout << x << " "; cout << endl;
        // for (auto x:h_from) cout << x << " "; cout << endl<<endl;
        
        long long code = h_from[nums.size()-1];
        long long x = code % base;
        code /= base;
        long long y = code % base;
        code /= base;
        long long z = code % base;
        // cout << x << y << z << endl;
        vector<int> result;
        result.push_back(z - k + 1);
        result.push_back(y - k + 1);
        result.push_back(x - k + 1);
        return result;
    }
};
// a: sum of subarray ends at i
// f: max sum of subarray before i
//     f[i] = max{f[i-1], a[i]}
// g: sum of two subarrays before i
//     g[i] = max{g[i-1], f[i-k] + a[i]}
// h: sum of three subarrays ends at i
//     h[i] = max{h[i-1], g[i-k] + a[i]}
