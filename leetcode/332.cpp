class Solution {
private:
    typedef multimap<string, string>::iterator trav_it;
    multimap<string, string> trav;
    vector<string> ans;
    
    void solve(string cur)
    {
        // cout << cur << endl;
        while (true)
        {
            pair<trav_it, trav_it> ret = trav.equal_range(cur);

            if (ret.first == ret.second) break;
            else
            {
                // cout << "\tnot yet" << endl;
                trav_it to_del=ret.first;
                string next = ret.first->second;
                for (trav_it it = ret.first; it != ret.second; ++it)
                {
                    if (it->second < next) 
                    {
                        next = it->second;
                        to_del = it;
                    }
                }
                // cout << "\t" << next << endl;
                
                trav.erase(to_del);
                solve(next);
            }
        }
        ans.push_back(cur);
    }
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) 
    {
        trav.clear();
        for (int i=0;i<tickets.size();++i)
            trav.emplace(tickets[i].first, tickets[i].second);
        
        ans.clear();
        solve("JFK");
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};