class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (empty()) return ;
        peek();
        s2.pop();
    }

    // Get the front element.
    int peek(void) {
        if (empty()) return 0;
        
        if (!s2.empty()) return s2.top();
        else
        {
            move();
            return s2.top();
        }
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty() && s2.empty();
    }
private:
    stack<int> s1;
    stack<int> s2;
    
    void move()
    {
        while (!s1.empty())
        {
            int tmp = s1.top();
            s1.pop();
            s2.push(tmp);
        }
    }
};
