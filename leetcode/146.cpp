class LRUCache{
private:
    map<int,int> map_kv;
    map<int,int> map_tk;
    map<int,int> map_kt;
    int op_count;
    int capacity;
    
public:
    LRUCache(int c) 
    {
        capacity = c;
        op_count = 0;
        map_kv.clear();
        map_tk.clear();
        map_kt.clear();
    }
    
    int get(int key) 
    {
        ++op_count;
        if (map_kv.find(key) == map_kv.end()) return -1;
        else
        {
            int old_time = map_kt[key];
            map_tk.erase(map_tk.find(old_time));
            map_tk.emplace(op_count, key);
            
            map_kt[key] = op_count;
            
            return map_kv[key];
        }
    }
    
    void set(int key, int value) 
    {
        ++op_count;
        if (map_kv.find(key) == map_kv.end())
        // insert new key
        {
            if (map_kv.size() == capacity)
            {
                map<int, int>::iterator it = map_tk.begin();
                int k = it->second;
                
                map_tk.erase(map_tk.begin());
                map_kt.erase(map_kt.find(k));
                map_kv.erase(map_kv.find(k));
            }
            
            map_kv.emplace(key, value);
            map_tk.emplace(op_count, key);
            map_kt.emplace(key, op_count);
        }
        else
        {
            int old_time = map_kt[key];
            map_tk.erase(map_tk.find(old_time));
            map_tk.emplace(op_count, key);
            
            map_kt[key] = op_count;
            map_kv[key] = value;
        }
    }
};