class Solution {
    
    typedef pair<int, int> ProjectType;
    
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        
        int n = Profits.size();
        
        vector<ProjectType> a;
        for (int i=0;i<n;++i)
            a.push_back(ProjectType(Profits[i], Capital[i]));
        
        sort(a.begin(), a.end(), [](ProjectType &x, ProjectType &y){return x.second < y.second;});
        
        priority_queue<int> que;
        int p = 0;
        while (p < a.size() && a[p].second <= W){
            que.push(a[p++].first);
        }
        
        for (int i=0;i<k;++i){
            if (que.empty()) break;
            W += que.top();
            que.pop();
            while (p < a.size() && a[p].second <= W){
                que.push(a[p++].first);
            }
        }
        
        return W;
    }
};

