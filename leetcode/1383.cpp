class Solution {
    typedef pair<long long, long long> Engineer;
    const int mode = 1000000007;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<Engineer> a;
        for (int i=0;i<n;++i)
            a.push_back(Engineer(efficiency[i], speed[i]));
        sort(a.begin(), a.end(), [](const Engineer &x, const Engineer &y){ 
            return x.first < y.first;
        });
        
        long long result = 0l;
        long long sum = 0;
        priority_queue <long long, vector<long long>, greater<long long> > que;
        for (int i=n-1;i>=0;--i){
            int e = a[i].first;
            que.push(a[i].second);
            sum += a[i].second;
            if (que.size() > k){
                sum -= que.top();
                que.pop();
            }
            result = max(result, sum * e);
        }
        return result % mode;
    }
};
