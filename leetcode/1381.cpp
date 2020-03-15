class CustomStack {
    vector<int> a;
    int n;
    
public:
    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
        if (a.size() >= n) return;
        a.push_back(x);
    }
    
    int pop() {
        if (a.empty()) return -1;
        int result = a[a.size()-1];
        a.pop_back();
        return result;
    }
    
    void increment(int k, int val) {
        for (int i=0;i<min(k,(int)a.size());++i)
            a[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
