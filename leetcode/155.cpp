class MinStack {
private:
    stack<int> a, m;
public:
    void push(int x) {
        a.push(x);
        if (m.empty()) m.push(x);
        else m.push(min(m.top(),x));
    }

    void pop() {
        a.pop();
        m.pop();
    }

    int top() {
        return a.top();
    }

    int getMin() {
        return m.top();
    }
};