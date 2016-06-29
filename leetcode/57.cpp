/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution 
{
private:
    struct  Interval_comparator
    {
        bool operator() (const Interval &a, const Interval& b) const
        {
            return a.end < b.end;
        }
    };

public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
    {
        int left = newInterval.start;
        int right = newInterval.end;
        
        set<Interval, Interval_comparator> s;
        s.clear();
        
        for (auto element : intervals)
            s.insert(element);
        
        set<Interval, Interval_comparator>::iterator it, it_tmp;
        it = lower_bound(s.begin(), s.end(), Interval(left,left), Interval_comparator());
        if (it == s.end() || it->start > right)
            s.insert(newInterval);
        else
        {
            int l = min(it->start, left);
            int r;
            while (it != s.end() && it->start <= right)
            {
                r = max(it->end, right);
                it_tmp = it++;
                s.erase(it_tmp);
            }
            s.insert(Interval(l,r));
        }
        
        vector<Interval> ans;
        ans.clear();
        for (auto element : s)
            ans.push_back(element);
        
        return ans;
    }
};