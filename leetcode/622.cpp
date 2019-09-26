class MyCircularQueue {
    int n;
    int p1, p2;
    vector<int> a;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        n = k+1;
        a = vector<int>(n);
        p1 = p2 = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        a[p2] = value;
        p2 = (p2 + 1)%n;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        p1 = (p1 + 1) % n;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) return -1;
        return a[p1];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) return -1;
        return a[(p2-1+n)%n];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return (p1 == p2);
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return ((p2 + 1) % n == p1);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
