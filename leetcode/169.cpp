template<typename T>
void get_majority(const vector<T> &a, bool &has_majority, T &majority){
    
    // majority element is the element appear more than a.size()/2 times
    // Note that [1,2,2,3] does not have majority
    if (a.empty()) has_majority = false;

    int count = 0;
    T m;
    for(auto x : a){
        if (count == 0) {
            m = x;
            ++count;
        }
        else {
            if (m == x) ++count; 
            else --count; 
        }
    }

    majority = m;
    count = 0;
    for (auto x : a) if (x == majority) ++count;
    has_majority = (count > a.size() /2);
}


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans;
        bool valid;
        get_majority(nums,valid,ans);
        return ans;
    }
};
