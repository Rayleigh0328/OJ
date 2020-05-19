class StockSpanner {
    const int inf = (1<<28);
    
    vector<int> a;
    deque<int> que;
    
public:
    StockSpanner() {
        a.push_back(inf);
        que.push_back(0);
    }
    
    int next(int price) {
        a.push_back(price);
        int cur_day = a.size()-1;
        while (a[que.back()] <= price) que.pop_back();
        int result = cur_day - que.back();
        que.push_back(cur_day);
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
