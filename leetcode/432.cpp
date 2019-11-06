class AllOne {
    typedef list<unordered_set<string>>::iterator ListIterator;
    
    unordered_map<string, int> key_to_value;
    unordered_map<int, ListIterator> value_to_it;
    list<unordered_set<string>> key_set_list;
    
    
    void emplace(const string& key, int value){
        // cout << "EMPLACE " << key << " to " << value << endl;
        ListIterator it;
        if (value == 1){
            if (value_to_it.find(1) != value_to_it.end())
                value_to_it[1]->emplace(key);
            else 
                value_to_it[1] = key_set_list.insert(key_set_list.begin(), {key});
            return;
        }
        
        if (value_to_it.find(value) != value_to_it.end()){
            it = value_to_it[value];
            it->emplace(key);
        }
        else if (value_to_it.find(value+1) != value_to_it.end()){
            value_to_it[value] = key_set_list.insert(value_to_it[value+1],{key});
        }
        else{
            it = value_to_it[value-1];
            ++it;
            value_to_it[value] = key_set_list.insert(it,{key});
        }
    }
    
    void erase(const string& key, int value){
        // cout << "ERASE " << key << " from " << value << endl;
        auto it = value_to_it[value];
        it->erase(key);
        if (it->empty()) {
            key_set_list.erase(it);
            value_to_it.erase(value);
        }
    }
    
public:
    /** Initialize your data structure here. */
    AllOne() {
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        // cout << "INC: " << key << endl;
        int old_value=-1, new_value;
        if (key_to_value.find(key) == key_to_value.end()){
            new_value = 1;
        }
        else{
            old_value = key_to_value[key];
            new_value = old_value + 1;
        }
        emplace(key, new_value);
        if (old_value != -1) erase(key, old_value);
        
        key_to_value[key] = new_value;
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        // cout << "DEC: " << key << endl;
        int old_value, new_value;
        if (key_to_value.find(key) == key_to_value.end()) return;
        old_value = key_to_value[key];
        new_value = old_value - 1;
        if (new_value > 0) emplace(key, new_value);
        erase(key, old_value);
        
        if (new_value > 0) key_to_value[key] = new_value;
        else key_to_value.erase(key);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        cout << "get max" << endl;
        // cout << key_set_list.size() << endl;
        if (key_set_list.empty()) return "";
        else return *key_set_list.rbegin()->begin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        cout << "get min" << endl;
        if (key_set_list.empty()) return "";
        else return *key_set_list.begin()->begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
