class Solution {
    
    void update_result(vector<vector<int>> &result, const vector<int> &left, const vector<vector<int>> &right){
        
        for (int j=0;j<right.size();++j){
            vector<int> c(left);
            for (auto x : right[j]) c.push_back(x);
            result.push_back(c);
        }
    }
    
    vector<vector<int>> k_sum(int k, const vector<int>& a, int start_pos, int target){
        vector<vector<int>> result;
        int n = a.size();
        
        if (k == 1) {
            for (int i=start_pos;i<n;++i)
                if (a[i] == target) {
                    result.push_back({a[i]});
                    break;
                }
            return result;
        }
        
        if (k == 2){
            int i = start_pos;
            int j = n - 1;
            int sum;
            while (i < j){
                sum = a[i] + a[j];
                if (sum > target) --j;
                else if (sum < target) ++i;
                else {
                    result.push_back({a[i],a[j]});
                    while (i+1<n && a[i+1]==a[i]) ++i;
                    while (j-1>=0 && a[j-1] == a[j]) --j;
                    --j;
                }
            }
            return result;
        }
        
        // k > 2
        for (int i=start_pos,next; i<n; i=next){
            next = i+1;
            while (next < n && a[next] == a[i]) ++next;
            if (next-i>=k && a[i] * k == target){
                result.push_back(vector<int>(k, a[i]));
            }
            for (int cnt=min(k-1,next-i); cnt>=1; --cnt){
                update_result(result, vector<int>(cnt, a[i]), k_sum(k-cnt, a, next, target-cnt*a[i]));
            }
        }
        return result;
    } 
    
    vector<vector<int>> k_sum(int k, vector<int>& a, int target){
        sort(a.begin(),a.end());
        return k_sum(k, a, 0, target);
    }
    
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        return k_sum(4,nums,target);
    }
};
