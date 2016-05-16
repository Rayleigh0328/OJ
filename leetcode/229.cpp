class Solution {
public:
    vector<int> majorityElement(vector<int>& a) 
    {
        if (a.empty()) return vector<int>();
        unordered_map<int, int> cnt;
        cnt.clear();
        for (int i=0;i<a.size();++i)
            if (cnt.find(a[i]) == cnt.end())
                cnt.emplace(a[i],1);
            else
                ++cnt[a[i]];
        
        unordered_map<int, int>::iterator it, max_it = cnt.begin();
        for (it = cnt.begin(); it != cnt.end(); ++it)
            if (it->second > max_it->second) max_it = it;
        
        vector<int> ans;
        ans.clear();
        if (max_it != cnt.end() && max_it->second > a.size()/3) 
            ans.push_back(max_it->first);
        else 
            return ans;
        cnt.erase(max_it);
        
        max_it = cnt.begin();
        for (it = cnt.begin(); it != cnt.end(); ++it)
            if (it->second > max_it->second) max_it = it;
        if (max_it != cnt.end() && max_it->second >  a.size()/3) 
            ans.push_back(max_it->first);
        return ans;
    }
};