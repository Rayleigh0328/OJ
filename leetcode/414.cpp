class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if (nums.empty()) return -1;
        
        priority_queue<int, vector<int>, greater<int>> heap;
        unordered_set<int> s;
        for (auto x : nums){
            if (s.find(x) != s.end()) continue;
            s.emplace(x);
            heap.push(x);
            if (heap.size() > 3) heap.pop();
        }
        if (heap.size() == 3) return heap.top();
        while (heap.size() != 1) heap.pop();
        return heap.top();
    }
};
