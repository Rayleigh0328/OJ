class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& a, int ind_diff, int val_diff) 
    {
        if (val_diff < 0) return false;
        
        set<long long> s;
        set<long long> mir;
        s.clear();
        mir.clear();
        
        set<long long>::iterator it;
        
        
        for (int i=0;i<a.size() && i<=ind_diff;++i)
        {
            // find same element
            if (s.find(a[i])!=s.end()) return true;
            
            it = s.lower_bound(a[i]);
            if (it!=s.end() && *it - a[i] <= val_diff) return true;
                
            it = mir.lower_bound(-a[i]);
            if (it != mir.end() && a[i] + *it <= val_diff) return true;
            
            s.insert(a[i]);
            mir.insert(-a[i]);
        }
        
        for (int i=ind_diff + 1; i<a.size();++i)
        {
            s.erase(a[i-ind_diff - 1]);
            mir.erase(-a[i-ind_diff -1]);
            
            // find same element
            if  (s.find(a[i])!=s.end()) return true;
            
            it = s.lower_bound(a[i]);
            if (it!=s.end() && *it - a[i] <= val_diff) return true;
                
            it = mir.lower_bound(-a[i]);
            if (it != mir.end() && a[i] + *it <= val_diff) return true;
            
            s.insert(a[i]);
            mir.insert(-a[i]);
        }
        
        return false;
    }
};