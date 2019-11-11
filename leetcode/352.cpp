typedef pair<int,int> Interval;
typedef set<Interval>::iterator SetIt;

struct cmp {
    bool operator() (const Interval &a, const Interval &b) const {
        return a.first < b.first;
    }
};

const int inf = (1<<30);

class SummaryRanges {
    
    set<Interval,cmp> interval_set;
    
    bool existed(int val){
        SetIt it = interval_set.upper_bound(Interval(val,0));
        // if (it == interval_set.end())
        //     printf("no upper bound for %d\n", val);
        // else 
        //     printf("upper bound for %d is (%d,%d)\n", val, it->first, it->second);
        if (it == interval_set.begin()) return false;
        --it;
        // printf("check (%d,%d) for value %d\n", it->first, it->second, val);
        return it->second >= val;
    }
    
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        // printf("add %d\n", val);
        if (existed(val)) return;
        SetIt next_it = interval_set.upper_bound(Interval(val,0));
        Interval next_interval;
        if (next_it == interval_set.end())
            next_interval = Interval(inf, inf);
        else 
            next_interval = *next_it;
        
        Interval prev_interval;
        if (next_it == interval_set.begin()){
            prev_interval=Interval(-inf, -inf);
        }
        else {
            SetIt prev_it = next_it; --prev_it;
            prev_interval = *prev_it;
        }
        
        bool remove_prev=false;
        bool remove_next=false;
        Interval to_add(val, val);
        if (prev_interval.second + 1 == val) {
            remove_prev = true;
            to_add = Interval(prev_interval.first, val);
        }
        if (val + 1 == next_interval.first) {
            remove_next = true;
            to_add = Interval(to_add.first, next_interval.second);
        }
        // printf("interval to add: (%d,%d)\n", to_add.first, to_add.second);
        if (remove_prev) interval_set.erase(prev_interval);
        if (remove_next) interval_set.erase(next_interval);
        
        interval_set.emplace(to_add);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        for (auto &e : interval_set){
            result.push_back({e.first, e.second});
        }
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
