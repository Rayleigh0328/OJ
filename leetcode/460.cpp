
class LFUCache {

    struct FreqNode{
        int freq;
        list<int> key_list;
        
        FreqNode():FreqNode(0){}
        FreqNode(int f):freq(f){}
    };
    
    typedef list<int>::iterator key_list_it;
    typedef list<FreqNode>::iterator freq_list_it;
    
    unordered_map<int, int> k_to_v;
    unordered_map<int, key_list_it> k_to_key_it;
    unordered_map<int, freq_list_it> k_to_freq_it;
    list<FreqNode> freq_list;
    int capacity;
    
    void increment_freq(int key, bool exist){
        freq_list_it fit = (exist?k_to_freq_it[key] : freq_list.begin());
        freq_list_it next_fit = fit; ++next_fit;
        if (next_fit == freq_list.end() || next_fit->freq != fit->freq + 1) 
            next_fit = freq_list.insert(next_fit, FreqNode(fit->freq + 1));
        // printf("get next_fit, freq: %d\n", next_fit->freq);
        if (exist) {
            // printf("erase existing key\n");
            fit->key_list.erase(k_to_key_it[key]);
            // printf("erase key\n");
            if (fit->key_list.empty()) freq_list.erase(fit);
            // printf("old value erased\n");
        }
        next_fit->key_list.push_back(key);
        k_to_freq_it[key] = next_fit;
        key_list_it kit = next_fit->key_list.end(); --kit;
        k_to_key_it[key] = kit;
    }
    
    void remove_lf(){
        // printf("remove least frequent used\n");
        freq_list_it fit = freq_list.begin(); ++fit;
        key_list_it kit = fit->key_list.begin(); 
        int key = *(kit);
        fit->key_list.erase(kit);
        if (fit->key_list.empty()) freq_list.erase(fit);
        k_to_v.erase(key);
        k_to_key_it.erase(key);
        k_to_freq_it.erase(key);
    }
    
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        freq_list.push_back(FreqNode(0));
    }
    
    int get(int key) {
        // printf("get %d\n", key);
        if (k_to_v.find(key) == k_to_v.end()) return -1;
        int result = k_to_v[key];
        increment_freq(key, true);
        return result;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        // printf("put %d, %d\n", key, value);
        if (k_to_v.find(key) == k_to_v.end()){
            if (k_to_v.size() == capacity) remove_lf();
            k_to_v.emplace(key, value);
            increment_freq(key, false);
        }
        else{
            k_to_v[key] = value;
            increment_freq(key, true);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
