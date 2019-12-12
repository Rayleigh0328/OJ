class Solution {
public:
    int equalSubstring(string s, string t, int max_cost) {
        if (s.empty()) return 0;
        if (max_cost < 0) return 0;
        
        int n = s.length();
        vector<int> a(n);
        for (int i=0;i<n;++i) a[i] = abs(s[i] - t[i]);
        
        int current_sum = 0;
        int ans = 0;
        queue<int> que;
        for (int x : a){
            que.push(x);
            current_sum += x;
            while (current_sum > max_cost){
                current_sum -= que.front();
                que.pop();
            }
            if (que.size() > ans) ans = que.size();
        }
        return ans;
    }
};
