class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        map<int, int> last_appr;
        last_appr.clear();
        for (int i=0; i<=255; ++i)
            last_appr.emplace(i,-1);
        vector<int> last;
        for (int i=0;i<s.size();++i)
        {
            last.push_back(last_appr[s[i]]);
            last_appr[s[i]] = i;
        }
        
        queue< pair<int, int> > que;
        while (!que.empty()) que.pop();
        set<int> pos_set;
        pos_set.clear();
        
        int ans = 0;
        
        for (int i=s.size()-1; i>=0; --i)
        {
            if (pos_set.find(i) != pos_set.end())
            {
                while (que.front().second != i)
                {
                    ans = max(ans, que.front().first - i);
                    set<int>::const_iterator tmp_it = pos_set.find(que.front().second);
                    if (tmp_it != pos_set.end()) pos_set.erase(tmp_it);
                    que.pop();
                }
                ans = max(ans, que.front().first - i);
                set<int>::const_iterator tmp_it = pos_set.find(que.front().second);
                if (tmp_it != pos_set.end())pos_set.erase(tmp_it);
                que.pop();
            }
            
            que.push(pair<int, int> (i,last[i]));
            pos_set.insert(last[i]);
        }
        
        ans = max(ans, (int)que.size());
        return ans;
    }
};