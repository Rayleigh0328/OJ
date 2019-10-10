class Solution {
    map<string, int> hour_count;
    map<string, int> minute_count;
    
    string convert(int k, bool pad){
        if (k < 10 && pad) return "0" + to_string(k);
        else return to_string(k);
    }
    
    void populate(int k, map<string,int>& mp, bool pad){
        int cnt=0;
        int tmp = k;
        while (tmp > 0){
            ++cnt;
            tmp -= (tmp&-tmp);
        }
        mp.emplace(convert(k, pad),cnt);
    }
    
    void solve(int h, int m, vector<string>& ans){
        vector<string> a;
        for (auto e : hour_count){
            if (e.second == h) a.push_back(e.first);
        }
        vector<string> b;
        for (auto e : minute_count){
            if (e.second == m) b.push_back(e.first);
        }
        
        for (int i=0; i<a.size(); ++i)
            for (int j=0; j<b.size(); ++j)
                ans.push_back(a[i]+":"+b[j]);
    }
    
public:
    vector<string> readBinaryWatch(int num) {
        
        for (int i=0;i<12;++i)
            populate(i, hour_count, false);
        for (int i=0;i<60;++i)
            populate(i, minute_count, true);
        
        vector<string>ans;
        for (int i=0;i<=num;++i)
            solve(i,num-i,ans);
        return ans;
    }
};
