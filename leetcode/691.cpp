class Solution {
    const int inf = (1<<29);
    
    int n, max_state;
    
    int get_next_state(int prev, const string &st, const string &target){
        vector<int> v(n, 0);
        for (int i=0;i<n;++i)
            if (prev & (1<<i)) v[i] = 1;
        int p1=0, p2=0;
        while (p1 < st.size() && p2 < n){
            if (v[p2] == 1) ++p2;
            else if (st[p1] == target[p2]) {v[p2] = 1; ++p1; ++p2;}
            else if (st[p1] > target[p2]) ++p2;
            else ++p1;
        }
        int result = 0;
        for (int i=0;i<n;++i)
            if (v[i]) result += (1<<i);
        return result;
    }
    
    void process(string &st, const unordered_set<char> &useful){
        string result;
        for (int i=0;i<st.size();++i)
            if (useful.find(st[i]) != useful.end())
                result.push_back(st[i]);
        sort(result.begin(), result.end());
        st = result;
    }
    
    void update(string &st, string &target, vector<int>&ans){
        int u,v;
        for (int u=0;u<max_state;++u){
            if (ans[u] == inf) continue;
            v = get_next_state(u, st, target);
            if ( ans[v] > ans[u] + 1) {
                ans[v] = ans[u] + 1;
            }
        }
    }
    
public:
    int minStickers(vector<string>& stickers, string target) {
         
        n = target.size();
        max_state = (1<<n);
        
        sort(target.begin(), target.end());
        unordered_set<char> useful;
        for (int i=0;i<n;++i) useful.emplace(target[i]);
        
        for (auto &st : stickers) process(st, useful);

        vector<int> ans(max_state, inf);
        ans[0] = 0;
        for (auto &st : stickers){
            update(st, target, ans);
        }
        
        return (ans[max_state-1] == inf ? -1 : ans[max_state-1]);
    }
};
