class DinnerPlates {
public:
    const int cap;
    
    vector<vector<int>> stacks;
    set<int> pushable;
    set<int> popable;
    int right_most = 0;

    DinnerPlates(int capacity):
        cap(capacity) 
    {    
    }
    
    void push(int val) {
        if (pushable.empty()) {
            pushable.insert(right_most++);
            stacks.push_back(*(new vector<int>));
        }

        int s_ind = *pushable.begin();
        stacks[s_ind].push_back(val);
        if (stacks[s_ind].size() == cap) pushable.erase(s_ind);
        popable.insert(s_ind);
    }
    
    int pop() {
        if (popable.empty()) return -1;
        int s_ind = *popable.rbegin();
        return popAtStack(s_ind);
    }
    
    int popAtStack(int s_ind) {
        if (s_ind >= right_most) return -1;
        if (stacks[s_ind].empty()) return -1;
        int result = stacks[s_ind][stacks[s_ind].size() - 1];
        stacks[s_ind].pop_back();
        if (stacks[s_ind].empty()) popable.erase(s_ind);
        pushable.insert(s_ind);
        return result;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
