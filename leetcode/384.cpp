class Solution {
    vector<int> original;
    vector<int> a;
public:
    Solution(vector<int>& nums) {
        original = a = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return (a = original);
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int pos;
        for (int i=a.size();i>0;--i){
            pos = rand() % i;
            swap(a[i-1], a[pos]);
        }
        return a;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
