class Solution {
    
    int ans_count;
    
    bool is_squareful(int k){
        int p = sqrt(k) + 1e-6;
        return (p*p == k);
    }
    
    void solve(vector<int>& current, multiset<int>& all_values){
        // cout << "current:"; for (auto x : current) cout << x << " "; cout << endl;
        
        if (all_values.empty()){
            ++ans_count;
            return;
        }
        
        set<int> diff_values;
        for (auto x : all_values) diff_values.emplace(x);
        
        for (auto x : diff_values){
            if (current.empty() || is_squareful(current.back() + x)){
                current.push_back(x);
                all_values.erase(all_values.find(x));
                
                solve(current, all_values);
                    
                current.pop_back();
                all_values.emplace(x);
            }
        }
    }   
    
public:
    int numSquarefulPerms(vector<int>& a) {
        
        multiset<int> ms;
        for (auto x : a) ms.emplace(x);
        
        vector<int> current;
        ans_count = 0;
        solve(current, ms);
        return ans_count;
    }
};
