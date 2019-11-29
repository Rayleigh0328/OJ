class Solution {
    
    typedef multiset<int>::iterator SetIterator;
    
    int get_max(const multiset<int> &s){
        SetIterator it = s.end(); 
        --it;
        return *it;
    }
    
    void remove_max(multiset<int> &s){
        SetIterator it = s.end(); --it;
        s.erase(it);
    }
    
    int get_min(const multiset<int> &s){
        return *s.begin();
    }
    
    void remove_min(multiset<int> &s){
        s.erase(s.begin());
    }
    
    void maintain(multiset<int> &lower, multiset<int> &higher){
        while (static_cast<int>(lower.size()) < static_cast<int>(higher.size()) - 1){
            int x = get_min(higher);
            remove_min(higher);
            lower.emplace(x);
        }
        while (lower.size() > higher.size()){
            int x = get_max(lower);
            remove_max(lower);
            higher.emplace(x);
        }
    }
    
    double get_mean(multiset<int>&lower, multiset<int>&higher){
        printf("%d, %d\n", lower.size(), higher.size());
        if (higher.size() == lower.size())
            return (static_cast<long long>(get_max(lower)) + get_min(higher)) / 2.0;
        else 
            return get_min(higher);
    }
    
    void remove_element(int x, multiset<int> &lower, multiset<int> &higher){
        SetIterator it;
        it = lower.find(x);
        if (it != lower.end()) lower.erase(it);
        else {
            it = higher.find(x);
            higher.erase(it);
        }
    }
    
public:
    vector<double> medianSlidingWindow(vector<int>& a, int k) {
        vector<double> result;
        if(k>a.size()) return result;
        multiset<int> lower, higher;
        for (int i=0;i<k;++i)
            lower.emplace(a[i]);
        maintain(lower, higher);
        result.push_back(get_mean(lower, higher));
        
        for (int i=k;i<a.size();++i){
            if (a[i] < get_min(higher)) lower.emplace(a[i]);
            else higher.emplace(a[i]);
            remove_element(a[i-k], lower, higher);
            maintain(lower, higher);
            result.push_back(get_mean(lower, higher));
        }
        
        return result;
    }
};
