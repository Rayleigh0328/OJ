class Solution {
private:
    typedef unordered_map<int, int> map_type;
    typedef unordered_map<int, int>::iterator map_it_type;
    struct freq_type
    {
        int value;
        int freq;
        freq_type(int v, int f):value(v), freq(f){};
        
        bool operator<(const freq_type &other) const
        {
            return freq < other.freq;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map_type cnt;
        cnt.clear();
        for (int i=0;i<nums.size();++i)
            if (cnt.find(nums[i]) == cnt.end()) cnt.emplace(nums[i],1);
            else ++cnt[nums[i]];
        
        // for (map_it_type it = cnt.begin(); it != cnt.end(); ++it)
        // {
        //     cout << it->first << " " << it->second << endl;
        // }
        
        multiset<freq_type> best;
        best.clear();
        
        for (map_it_type it = cnt.begin(); it != cnt.end(); ++it)
        {
            best.insert(freq_type(it->first, it->second));
            if (best.size() > k)
                best.erase(best.begin());
        }
        
        // cout << "size" << best.size() << endl;
        vector<int> ans;
        ans.clear();
        for (multiset<freq_type>::reverse_iterator it = best.rbegin(); it != best.rend(); ++it)
            ans.push_back(it->value);
        return ans;
    }
};