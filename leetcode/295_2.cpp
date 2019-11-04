class MedianFinder {
    priority_queue<int> smaller_half;
    priority_queue<int, vector<int>, greater<int>> larger_half;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (smaller_half.empty()) smaller_half.push(num);
        else 
            if (smaller_half.top() >= num) smaller_half.push(num);
            else larger_half.push(num);
        
        // adjust between smaller and larger half
        while (larger_half.size() > smaller_half.size()){
            int tmp = larger_half.top();
            larger_half.pop();
            smaller_half.push(tmp);
        }
        while (smaller_half.size() > larger_half.size() + 1){
            int tmp = smaller_half.top();
            smaller_half.pop();
            larger_half.push(tmp);
        }
    }
    
    double findMedian() {
        assert(!smaller_half.empty());
        if (smaller_half.size() == larger_half.size()){
            return (smaller_half.top() + larger_half.top()) / 2.0;
        }
        else {
            return smaller_half.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
