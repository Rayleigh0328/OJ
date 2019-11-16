class RandomizedSet {
    
    const int SPECIAL=-2147483648;
    const double RESIZE_THRESHOLD = 0.5;
    
    vector<int> a;
    list<int> available_pos;
    unordered_map<int, int> value_to_pos;
    
    void resize(){
        vector<int> new_a;
        available_pos.clear();
        value_to_pos.clear();
        for (int i=0;i<a.size();++i){
            if (a[i] != SPECIAL) {
                value_to_pos[a[i]] = new_a.size();
                new_a.push_back(a[i]);
            }
        }
        a = new_a;
    }
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (value_to_pos.find(val) != value_to_pos.end()) return false;
       
        if (available_pos.empty()){
            value_to_pos.emplace(val, a.size());
            a.push_back(val);
        }
        else {
            int pos = *available_pos.begin();
            available_pos.erase(available_pos.begin());
            a[pos] = val;
            value_to_pos.emplace(val, pos);
        }
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (value_to_pos.find(val) == value_to_pos.end()) return false;
        
        int pos = value_to_pos[val];
        a[pos] = SPECIAL;
        value_to_pos.erase(val);
        available_pos.push_back(pos);
        
        if (static_cast<double>(available_pos.size()) / a.size() > RESIZE_THRESHOLD) resize();
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int pos = rand() % a.size();
        if (a[pos] != SPECIAL) return a[pos];
        else return getRandom();
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
