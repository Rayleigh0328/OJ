class Solution {
private:
    const long long inf = 1ll<<60ll;
    
    struct sum_type
    {
        long long sum;
        int ind;
        
        sum_type(long long s, int i):sum(s),ind(i){}
    };
    
    vector<sum_type> s;
    
    bool static cmp(const sum_type &x, const sum_type &y)
    {
        return x.sum < y.sum;
    }
    
    int find(int left, int right, long long k)
    {
        if (left == right) return left;
        if (left == right - 1)
            return (s[left].sum >=k)?left:right;
        
        int mid = (left + right)/2;
        
        if (s[mid].sum >= k) 
            return find(left, mid, k);
        else
            return find(mid+1, right, k);
    }
    
public:
    int countRangeSum(vector<int>& a, int L, int U) 
    {
        s.clear();    
        s.push_back(sum_type(0,-1));
        
        for (int i=0;i<a.size();++i)
            s.push_back(sum_type(a[i] + s[i].sum,i));
        s.push_back(sum_type(inf, -1));
        
        // for (int i=0;i<s.size();++i)
        //     cout << s[i].sum << ":" << s[i].ind << " ";
        // cout << endl;
        
        sort(s.begin(), s.end(), cmp);
        
        // for (int i=0;i<s.size();++i)
        //     cout << s[i].sum << ":" << s[i].ind << " ";
        // cout << endl;
        
        int ans = 0;
        
        long long up, low;
        for (int i=0;i<s.size()-1;++i)
        {
            up = U + s[i].sum + 1;
            low = L + s[i].sum;
            
            int ad1 = find(0, s.size()-1, low);
            int ad2 = find(0,s.size()-1,up);
            // cout << low << " " << up << " " << s[i].ind << endl;
            // cout << "\t" << ad1 << " " << ad2 << endl;
            for (int j=ad1; j<ad2; ++j)
                if (s[j].ind > s[i].ind) ++ans;
        }
        
        return ans;   
    }
};