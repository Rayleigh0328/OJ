typedef pair<int, int> Interval;

class Solution {
    int inf = (1<<30);

    bool in_interval(int x, Interval range){
        return range.first < x  && x < range.second;
    }

public:
    bool find132pattern(vector<int>& nums) {
        // special case
        if (nums.size() < 3) return false;

        // push [inf, inf] to the bottom to avoid empty check
        stack<Interval> stack;
        stack.push(Interval(inf, inf));
        Interval current(nums[0], nums[0]);
        int x;
        for (int i=1; i<nums.size();++i){
            x = nums[i]; 
            if (in_interval(x, current)) return true;
            if (x == current.first || x == current.second) continue;
            if (x < current.first) {
                stack.push(current);
                current = Interval(x,x);
                continue;
            }
            if (x > current.second){
                current.second = x;
                if (in_interval(x, stack.top())) return true;
                while (x >= stack.top().second){
                    stack.pop();
                    if (in_interval(x, stack.top())) return true;
                }
            }
        }
        return false;       
    }
};
