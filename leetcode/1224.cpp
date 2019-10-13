class Solution {
    
    int get_max(const set<int> &s){
        return *s.rbegin();
    }
    
    int get_min(const set<int> &s){
        return *s.begin();
    }
    
    int unique(int k, const multiset<int>& ms){
        auto it = ms.lower_bound(k);
        int x = *it;
        ++it;
        if (it == ms.end()) return true;
        int y = *it; 
        if (y!=x) return true;
        return false;
    }
    
    void print(const multiset<int> &ms){
        for (auto x : ms)
            cout << x << " ";
        cout << endl;
    }

    void print(const set<int> &s){
        for (auto x : s)
            cout << x << " ";
        cout << endl;
    }


    bool check(const set<int>& s, const multiset<int>& ms){
        /*
        print(s);
        print(ms);
        printf("max, min in s: %d, %d\n", get_max(s), get_min(s));
        printf("max is unique: %d\n", unique(get_max(s), ms));
        */
        if (ms.size() == 1) return true;
        if (s.size() == 1 && (*s.begin()) == 1) return true;
        if (s.size() == 2){
            if (get_max(s) == get_min(s) + 1 && unique(get_max(s), ms)) return true;
            if (s.find(1) != s.end() && unique(1, ms)) return true;
        }
        return false;
    }
    
public:
    int maxEqualFreq(vector<int>& a) {
        map<int, int> value_count;
        set<int> freq_set;
        multiset<int> freq_multiset;
        int ans = 0;
        for (int i=0;i<a.size();++i){
            //printf("process posiiton %d\n", i);
            if (value_count.find(a[i]) == value_count.end()){
                value_count.emplace(a[i],1);
                freq_set.emplace(1);
                freq_multiset.emplace(1);
            }
            else {
                // remove old occurence number
                int tmp = value_count[a[i]];
                auto it = freq_multiset.find(tmp);
                freq_multiset.erase(it);
                if (freq_multiset.find(tmp) == freq_multiset.end())
                    freq_set.erase(tmp);
                // add new occurrence 
                ++value_count[a[i]];
                ++tmp;
                freq_set.emplace(tmp);
                freq_multiset.emplace(tmp);
            }
            
            if (check(freq_set, freq_multiset)) ans = i;
        }
        return ans+1;
    }
};

