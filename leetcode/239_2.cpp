class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n = a.size();
        if (n < k || k < 1) return {};
        deque<int> que;
        for (int i=0;i<k;++i){
            while (!que.empty() && a[i] > a[que.back()]) 
                que.pop_back();
            que.push_back(i);
        }
        vector<int> ans;
        ans.push_back(a[que.front()]);
        for (int i=k;i<n;++i){
            // remove a[i-k]
            if (que.front() == i-k) que.pop_front();
            // push a[k]
            while (!que.empty() && a[i] > a[que.back()])
                que.pop_back();
            que.push_back(i);
            ans.push_back(a[que.front()]);
        }
        return ans;
    }
};
