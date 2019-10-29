class Solution {
    
    int get_max(vector<int>&a){
        int ans = a[0];
        for (auto x : a)
            if (x > ans) ans = x;
        return ans;
    }
    
    int get_min(vector<int>&a){
        int ans = a[0];
        for (auto x : a)
            if (x < ans) ans = x;
        return ans;
    }
    
public:
    int maximumGap(vector<int>& a) {
        int n = a.size();
        if (n < 2) return 0;
        int max_val = get_max(a);
        int min_val = get_min(a);
        if (n == 2) return max_val - min_val;
        if (max_val == min_val) return 0;
        int len = ceil((max_val - min_val) / (n-1) + 1e-8);
        // printf("total element: %d, min: %d, max: %d, bucket_size: %d\n", n, min_val, max_val, len);
        
        vector<vector<int>> bucket(n+1);
        int b;
        for (auto x : a){
            b = (x - min_val)/len;
            if (b > n) cout << x << " " << b << endl;
            bucket[b].push_back(x);
        }
        // printf("bucket created\n");
        
        vector<int> bucket_min(n+1,-1);
        vector<int> bucket_max(n+1,-1);
        for (int i=0;i<=n;++i){
            for (auto x : bucket[i]){
                if (bucket_min[i] == -1 || bucket_min[i] > x) bucket_min[i] = x; 
                if (bucket_max[i] == -1 || bucket_max[i] < x) bucket_max[i] = x;
            }
        }
    
        int ans = 0;
        int left=0, right=0;
        while (left <= n && bucket_max[left] == -1) ++left;
        while (left <= n){
            right = left + 1;
            while (right <= n && bucket_min[right] == -1) ++right;
            if (right == n+1) break;
            ans = max(ans, bucket_min[right] - bucket_max[left]);
            left = right;
        }
        return ans; 
    }
};
