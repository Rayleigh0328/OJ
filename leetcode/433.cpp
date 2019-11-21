class Solution {
    
    bool has_edge(const string &s1, const string &s2){
        int count = 0;
        for (int i=0;i<s1.length();++i)
            if (s1[i] != s2[i]) ++count;
        return (count == 1);
    }
    
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        // bank.push_back(end);
        
        unordered_map<string, int> dist;
        queue<string> que;
        
        que.push(start);
        dist[start]=0;
        
        while (!que.empty()){
            string s = que.front();
            que.pop();
            for (auto next_s : bank){
                if (dist.find(next_s) == dist.end() && has_edge(s, next_s)){
                    que.push(next_s);
                    dist[next_s] = dist[s] + 1;
                }
            }
        }
        if (dist.find(end) == dist.end()) return -1;
        else return dist[end];
    }
};
