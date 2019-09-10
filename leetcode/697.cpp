class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // start, map: value --> start index
        // end, map: value --> end index
        // freq, map: value --> freq count
        // find values with max freq, for each of these value
        // get min interval from start and end map
        unordered_map<int, int> start;
        unordered_map<int, int> end;
        unordered_map<int, int> freq;
        for (int i=0;i<nums.size();++i){
            if (freq.find(nums[i]) == freq.end()) {
                freq[nums[i]] = 1;
                start[nums[i]] = i;
                end[nums[i]] = i;
            }
            else{
                ++freq[nums[i]];
                end[nums[i]]=i;
            }
        }
        int max_freq = 0;
        for (auto it = freq.begin(); it != freq.end(); ++it)
            if (it->second > max_freq) max_freq = it->second;
        vector<int> candidate;
        for (auto it = freq.begin(); it != freq.end(); ++ it)
            if (it->second == max_freq) candidate.push_back(it->first);
        
        int ans = nums.size();
        for (int value : candidate)
            ans = min(ans, end[value] - start[value] + 1);
        return ans;
    }
};
