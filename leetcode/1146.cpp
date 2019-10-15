class SnapshotArray {
    const long long base = 100000ll;
    
    long long encode(int index, int snap){
        return -(index * base + snap);
    }
    
    map<long long, int> a;
    int current_snap = 0;
public:
    SnapshotArray(int length) {
        a.clear();
        for (int i=0;i<length;++i)
            a.emplace(encode(i,current_snap),0);
    }
    
    void set(int index, int val) {
        a[encode(index,current_snap)] = val;
    }
    
    int snap() {
        return current_snap++;
    }
    
    int get(int index, int snap_id) {
        return a.lower_bound(encode(index, snap_id)) -> second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
