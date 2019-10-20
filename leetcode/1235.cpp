struct Job{
    int start;
    int end;
    int profit;
    
    Job(int s, int e, int p):start(s),end(e),profit(p){}
    
    bool operator <(const Job& other){
        return end < other.end;
    }
};

int find_leq(
        const std::vector<Job>& v, 
        int start, 
        int end, 
        int key
        )
{
    int mid ;
    while (start < end){
        if (start == end - 1) return (v[start].end <= key ? start : -1);
        if (start == end - 2) {
            if (v[start+1].end <= key) return start + 1;
            else if (v[start].end <= key) return start;
            else return -1;
        }
         
        mid = (start + end) / 2;
        if (v[mid].end <= key) start = mid;
        else end = mid; 
    }
    return -1;
}

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<Job> a;
        for (int i=0; i<n; ++i)
            a.push_back(Job(startTime[i], endTime[i], profit[i]));
        
        sort(a.begin(), a.end());
        
        vector<int> f(n,0);
        for (int i=0;i<n;++i){
            int prev = find_leq(a,0,i,a[i].start);
            f[i] = (i>0?f[i-1]:0);
            f[i] = max(f[i], a[i].profit + (prev == -1 ? 0 : f[prev]) );
        }
        
        return f[n-1];
    }
};
