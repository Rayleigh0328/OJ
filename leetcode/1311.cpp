class Solution {
    
    int n;
    vector<int> dist;
    
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        
        int n = friends.size();
        // bfs(id);
        queue<int> que;
        que.emplace(id);
        dist = vector<int>(n, -1);
        dist[id] = 0;
        while (!que.empty()){
            int cur = que.front();
            que.pop();
            
            for (auto next : friends[cur]){
                if (dist[next] != -1) continue;
                else{
                    dist[next] = dist[cur] + 1;
                    que.push(next);
                }
            }
        }
        
        unordered_set<int> layer;
        for (int i=0;i<n;++i)
            if (dist[i] == level)
                layer.emplace(i);
        
        unordered_map<string, int> watch_count;
        for (int uid : layer){
            for (string &x : watchedVideos[uid])
                ++watch_count[x];
        }
        
        vector<string> ans;
        for (auto &e : watch_count)
            ans.push_back(e.first);
        sort(ans.begin(), ans.end(), [&watch_count](const string &x, const string &y){
            if (watch_count[x] < watch_count[y]) return true;
            if (watch_count[x] > watch_count[y]) return false;
            return x < y;
        });
        return ans;
    }
};
