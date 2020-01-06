class Solution {
public:
    bool canReach(vector<int>& a, int start) {
        int n = a.size();
        vector<bool> visited(n, false);
        queue<int> que;
        que.push(start);
        while (!que.empty()){
            int cur = que.front();
            visited[cur] = true;
            que.pop();
            
            for (int i=-1;i<=1;i+=2){
                int next = cur + i * a[cur];
                if (0 <= next && next < n && visited[next] == false)
                    que.push(next);
            }
        }
        
        for (int i=0;i<n;++i)
            if (a[i] == 0 && visited[i]) return true;
        return false;
    }
};
